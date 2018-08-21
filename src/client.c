//
// Created by 何延龙 on 2018/8/2.
//
#include "php.h"
#include <zend_interfaces.h>
#include "ext/standard/php_var.h"
#include "main/SAPI.h"
#include <string.h>
#include "common.h"
#include "client.h"
#include "ext/standard/php_array.h"
#include "ext/standard/php_string.h"

zend_class_entry *guzzle_client_ce;

/**
 * arginfo
 */
//ZEND_BEGIN_ARG_INFO_EX(arginfo___construct, 0, 0, 1)
//                ZEND_ARG_INFO(0, config)
//ZEND_END_ARG_INFO()
//

ZEND_BEGIN_ARG_INFO_EX(arginfo___call, 0, 0, 2)
                ZEND_ARG_INFO(0, name)
                ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

static zend_function_entry guzzle_client_method[] = {
        PHP_ME(Client, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_ME(Client, configureDefaults, NULL, ZEND_ACC_PRIVATE)
        PHP_ME(Client, __call, arginfo___call, ZEND_ACC_PUBLIC)
        PHP_ME(Client, request, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(Client, requestAsync, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(Client, buildUri, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(Client, transfer, NULL, ZEND_ACC_PUBLIC)

        PHP_FE_END
};

void guzzle_init_client() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, GUZZLE_NS, "Client", guzzle_client_method);

    guzzle_client_ce = zend_register_internal_class(&ce);
//    zend_class_implements(spinach_container_ce, 1, spl_ce_ArrayAccess);

    zend_declare_property_null(guzzle_client_ce, "config", sizeof("config") - 1, ZEND_ACC_PRIVATE);
}

PHP_METHOD (Client, __construct) {

    zval *config;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|a", &config) == FAILURE) {
        return;
    }

    if (Z_TYPE_P(config) != IS_ARRAY) {
        // todo bug
        config = (zval *) malloc(sizeof(zval));
        array_init(config);
    }

    zend_string *callable_name = NULL;
    if (!zend_hash_str_exists(Z_ARRVAL_P(config), ZEND_STRL("handler"))) {
        zval handler;
        zend_call_method(getThis(), guzzle_handler_stack_ce, NULL, ZEND_STRL("create"), &handler, 0, NULL, NULL);

        zval handle_key;
        ZVAL_STRING(&handle_key, "handler");
        zend_hash_add(Z_ARRVAL_P(config), handle_key.value.str, &handler);

    } else if (!zend_is_callable(zend_hash_str_find(Z_ARRVAL_P(config), ZEND_STRL("handler")), 0, &callable_name)) {
        // todo
        php_printf("异常");
    }

    // Convert the base_uri to a UriInterface
    // todo

    zend_call_method(getThis(), guzzle_client_ce, NULL, ZEND_STRL("configuredefaults"), NULL, 1, config, NULL);

}

PHP_METHOD (Client, configureDefaults) {
    zval *config;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "a", &config) == FAILURE) {
        RETURN_FALSE;
    }

    zval defaults;
    array_init(&defaults);

    // todo allow_redirects

    zend_string *default_key = zend_string_init(ZEND_STRL("http_errors"), 0);
    zval default_bool_value;
    ZVAL_BOOL(&default_bool_value, 1);
    zend_hash_add(Z_ARRVAL_P(&defaults), default_key, &default_bool_value);

    default_key = zend_string_init(ZEND_STRL("decode_content"), 0);
    ZVAL_BOOL(&default_bool_value, 1);
    zend_hash_add(Z_ARRVAL_P(&defaults), default_key, &default_bool_value);

    default_key = zend_string_init(ZEND_STRL("verify"), 0);
    ZVAL_BOOL(&default_bool_value, 1);
    zend_hash_add(Z_ARRVAL_P(&defaults), default_key, &default_bool_value);

    default_key = zend_string_init(ZEND_STRL("cookies"), 0);
    ZVAL_BOOL(&default_bool_value, 0);
    zend_hash_add(Z_ARRVAL_P(&defaults), default_key, &default_bool_value);

//    zend_string_free(default_key);


    zval func_getenv;
    ZVAL_STRING(&func_getenv, "getenv");
    zval func_getenv_ret_ptr;
    zval func_getenv_params;
    ZVAL_STRING(&func_getenv_params, "HTTP_PROXY");
    call_user_function(EG(function_table), NULL, &func_getenv, &func_getenv_ret_ptr, 1, &func_getenv_params);


    zval proxy;
    array_init(&proxy);

    if (strncasecmp(sapi_module.name, "cli", 3) == 0 && Z_TYPE_P(&func_getenv_ret_ptr) == IS_STRING &&
        strcasecmp(Z_STRVAL(func_getenv_ret_ptr), "") != 0) {
        zend_hash_add(Z_ARRVAL_P(&proxy), zend_string_init(ZEND_STRL("http"), 0), &func_getenv_ret_ptr);
    }

    php_array_merge(config->value.arr, defaults.value.arr);

    zend_update_property(guzzle_client_ce, getThis(), ZEND_STRL("config"), config);

}

PHP_METHOD (Client, __call) {
    zend_string *name;
    zval *arguments;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "Sa", &name, &arguments) == FAILURE) {
        RETURN_FALSE;
    }

    zval *uri = zend_hash_index_find(Z_ARRVAL_P(arguments), 0);
    zval *opts = zend_hash_index_find(Z_ARRVAL_P(arguments), 1);

}

PHP_METHOD (Client, request) {
    zval *method, uri, options;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "zzz", &method, &uri, &options) == FAILURE) {
        RETURN_FALSE;
    }

    zval *promist = (zval *) emalloc(sizeof(zval));
    zend_call_method(getThis(), guzzle_client_ce, NULL, ZEND_STRL("requestasync"), promist, 0, NULL, NULL);

    zend_call_method(&promist, ce, NULL, ZEND_STRL("wait"), return_value, 0, NULL, NULL);
    efree(&promist);

}

PHP_METHOD (Client, requestAsync) {
    zval *method, uri, options;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "zzz", &method, &uri, &options) == FAILURE) {
        RETURN_FALSE;
    }
}

PHP_METHOD (Client, buildUri) {

}

PHP_METHOD (Client, transfer) {

}