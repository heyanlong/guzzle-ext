//
// Created by 何延龙 on 2018/8/9.
//

#include "php.h"
#include "common.h"
#include "middleware.h"
#include <zend_closures.h>

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
    php_printf("121");
    zend_execute_data *a = EG(current_execute_data);

    zend_array b = EG(symbol_table);

    if(zend_hash_str_find(&b, ZEND_STRL("handler"))) {
        php_printf("121");
    }else{
    }


}

static void http_errors_1(INTERNAL_FUNCTION_PARAMETERS) {
    zval
    f;
    zend_function
    zf;
    HashTable static_variables;
    zend_hash_init(&static_variables, 10, NULL, NULL, 0);

    zval
    te;
    ZVAL_LONG(&te, 12121);
    zend_hash_update(&static_variables, zend_string_init(ZEND_STRL("handler"), 0), &te);


    zf.common.type = ZEND_INTERNAL_FUNCTION;
    zf.common.arg_info = NULL;
    zf.common.num_args = 0;
    zf.common.required_num_args = 0;
    zf.common.prototype = NULL;
    zf.common.scope = NULL;
    zf.internal_function.handler = http_errors_2;


    zend_create_closure(&f, &zf, NULL, NULL, NULL);

//    f.value.func->op_array.static_variables = &static_variables;
    zend_closure_bind_var(&f, zend_string_init(ZEND_STRL("handler"), 0), &te);

    zval
    retval;
    zend_fcall_info fci;
    zend_fcall_info_cache fcc;
    zend_fcall_info_init(&f, 0, &fci, &fcc, NULL, NULL);

    fci.retval = &retval;
    fci.param_count = 0;
    fci.params = NULL;

    zend_call_function(&fci, &fcc);

    RETURN_ZVAL(&f, 1, 0);
}


PHP_METHOD (Middleware, httpErrors) {

    zval
    f;
    zend_function
    zf;
    zf.common.type = ZEND_INTERNAL_FUNCTION;
    zf.common.arg_info = NULL;
    zf.common.num_args = 0;
    zf.common.required_num_args = 0;
    zf.common.prototype = NULL;
    zf.common.scope = NULL;
    zf.internal_function.handler = http_errors_1;
    zend_create_closure(&f, &zf, NULL, NULL, NULL);

    RETURN_ZVAL(&f, 1, 0);
}