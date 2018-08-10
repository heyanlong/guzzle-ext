/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_guzzle.h"
#include "src/client.h"
#include "src/cookie/cookie_jar_interface.h"
#include "src/cookie/cookie_jar.h"
#include "src/cookie/set_cookie.h"
#include "src/handler_stack.h"
#include "src/middleware.h"

/* If you declare any globals in php_guzzle.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(guzzle)
*/

/* True global resources - no need for thread safety here */
static int le_guzzle;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("guzzle.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_guzzle_globals, guzzle_globals)
    STD_PHP_INI_ENTRY("guzzle.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_guzzle_globals, guzzle_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_guzzle_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION (confirm_guzzle_compiled) {

    zval *config;

//    array_init(&config);

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|a", &config) == FAILURE) {
        return;
    }

    php_printf("%d\r\n", Z_TYPE_P(zend_hash_find(Z_ARRVAL_P(config), zend_string_init(ZEND_STRL("handler"), 0))));


    zend_string *callable_name = NULL;
    if (!config || !zend_hash_str_exists(Z_ARRVAL_P(config), ZEND_STRL("handler"))) {
        // todo
        php_printf("yes");
    } else if (!zend_is_callable(zend_hash_str_find(Z_ARRVAL_P(config), ZEND_STRL("handler")), 0, &callable_name)) {
        // todo
        php_printf("异常");
    }

    RETURN_TRUE;
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_guzzle_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_guzzle_init_globals(zend_guzzle_globals *guzzle_globals)
{
	guzzle_globals->global_value = 0;
	guzzle_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION (guzzle) {
    /* If you have INI entries, uncomment these lines
    REGISTER_INI_ENTRIES();
    */
    guzzle_init_client();
    guzzle_init_middleware();
    guzzle_init_cookie_jar_interface();
    guzzle_init_cookie_jar();
    guzzle_init_set_cookie();
    guzzle_init_handler_stack();
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION (guzzle) {
    /* uncomment this line if you have INI entries
    UNREGISTER_INI_ENTRIES();
    */
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION (guzzle) {
#if defined(COMPILE_DL_GUZZLE) && defined(ZTS)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION (guzzle) {
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION (guzzle) {
    php_info_print_table_start();
    php_info_print_table_header(2, "guzzle support", "enabled");
    php_info_print_table_end();

    /* Remove comments if you have entries in php.ini
    DISPLAY_INI_ENTRIES();
    */
}
/* }}} */

/* {{{ guzzle_functions[]
 *
 * Every user visible function must have an entry in guzzle_functions[].
 */
const zend_function_entry guzzle_functions[] = {
        PHP_FE(confirm_guzzle_compiled, NULL)        /* For testing, remove later. */
        PHP_FE_END    /* Must be the last line in guzzle_functions[] */
};
/* }}} */

/* {{{ guzzle_module_entry
 */
zend_module_entry guzzle_module_entry = {
        STANDARD_MODULE_HEADER,
        "guzzle",
        guzzle_functions,
        PHP_MINIT(guzzle),
        PHP_MSHUTDOWN(guzzle),
        PHP_RINIT(guzzle),        /* Replace with NULL if there's nothing to do at request start */
        PHP_RSHUTDOWN(guzzle),    /* Replace with NULL if there's nothing to do at request end */
        PHP_MINFO(guzzle),
        PHP_GUZZLE_VERSION,
        STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GUZZLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(guzzle)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
