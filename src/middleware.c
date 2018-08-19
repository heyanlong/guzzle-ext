//
// Created by 何延龙 on 2018/8/9.
//

#include "php.h"
#include "common.h"
#include "middleware.h"
#include <zend_closures.h>
#include <zend_compile.h>

#include "ext/standard/php_var.h"

zend_class_entry *guzzle_middleware_ce;

static zend_function_entry guzzle_middleware_method[] = {
        PHP_ME(Middleware, httpErrors, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
        PHP_FE_END
};

void guzzle_init_middleware() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, GUZZLE_NS, "Middleware", guzzle_middleware_method);

    guzzle_middleware_ce = zend_register_internal_class(&ce);
    guzzle_middleware_ce->ce_flags |= ZEND_ACC_FINAL;

}


static void http_errors_2(INTERNAL_FUNCTION_PARAMETERS) {

    HashTable *static_variables = EX(func)->internal_function.prototype->op_array.static_variables;
    zval *handler = zend_hash_str_find(static_variables, ZEND_STRL("handler"));

    zval *request,*options;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "zz", &request,&options) == FAILURE) {
        RETURN_FALSE;
    }


    if(handler) {
        php_printf("121");
    }else{
    }


}

static const zend_arg_info arginfo_http_error_1[] = {
        ZEND_ARG_CALLABLE_INFO(0, handler, 0)
};

static void http_errors_1(INTERNAL_FUNCTION_PARAMETERS) {

    zval *handler;
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "z", &handler) == FAILURE) {
        RETURN_FALSE;
    }


    zend_function
    zf;
    HashTable *static_variables = emalloc(sizeof(HashTable));
    zend_hash_init(static_variables, HT_MIN_SIZE, NULL, NULL, 0);
    zend_hash_update(static_variables, zend_string_init(ZEND_STRL("handler"), 0), handler);


    zf.common.type = ZEND_INTERNAL_FUNCTION;
    zf.common.arg_info = NULL;
    zf.common.num_args = 0;
    zf.common.required_num_args = 0;
    zf.common.prototype = NULL;
    zf.common.scope = NULL;
    zf.internal_function.handler = http_errors_2;


    zend_create_closure(return_value, &zf, NULL, NULL, NULL);

    return_value->value.func->op_array.static_variables = static_variables;
}


PHP_METHOD (Middleware, httpErrors) {

    zend_function
    zf;
    zf.common.type = ZEND_INTERNAL_FUNCTION;
    zf.common.function_name = NULL;
    zf.common.arg_info = &arginfo_http_error_1;
    zf.common.num_args = 1;
    zf.common.required_num_args = 1;
    zf.common.prototype = NULL;
    zf.common.scope = NULL;
    zf.internal_function.handler = http_errors_1;
    zf.internal_function.arg_info = &arginfo_http_error_1;
    zf.internal_function.num_args = 1;
    zf.internal_function.required_num_args = 1;
    zf.internal_function.function_name = NULL;
    zf.internal_function.prototype = NULL;
    zf.internal_function.scope = NULL;
    zend_create_closure(return_value, &zf, NULL, NULL, getThis());

}