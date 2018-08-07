//
// Created by 何延龙 on 2018/8/6.
//
#include "php.h"
#include "common.h"
#include "handler_stack.h"
//#include <zend_interfaces.h>

zend_class_entry *guzzle_handler_stack_ce;

static zend_function_entry guzzle_handler_stack_method[] = {
        PHP_ME(HandlerStack, create, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
        PHP_ME(HandlerStack, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_FE_END
};

void guzzle_init_handler_stack() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, GUZZLE_NS, "HandlerStack", guzzle_handler_stack_method);

    guzzle_handler_stack_ce = zend_register_internal_class(&ce);
//    zend_class_implements(spinach_container_ce, 1, spl_ce_ArrayAccess);

//    zend_declare_property_null(guzzle_client_ce, "config", sizeof("config") - 1, ZEND_ACC_PRIVATE);
}
//
PHP_METHOD (HandlerStack, create) {
//    zval self;
//    zend_call_method(getThis(), guzzle_handler_stack_ce, NULL, ZEND_STRL("__construct"), &self, 0, NULL, NULL);
////    RETURN_ZVAL(getThis(), 1, 0);
}
//
PHP_METHOD (HandlerStack, __construct) {

}