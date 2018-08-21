//
// Created by 何延龙 on 2018/8/21.
//
#include "php.h"
#include "../../common.h"
#include "message_interface.h"

zend_class_entry *guzzle_psr_http_message_message_interface_ce;

static zend_function_entry guzzle_init_psr_http_message_message_interface_method[] = {
        PHP_ABSTRACT_ME(MessageInterface, getProtocolVersion, NULL)
        PHP_ABSTRACT_ME(MessageInterface, withProtocolVersion, arginfo_psr_http_message_withProtocolVersion)
        PHP_FE_END
};

void guzzle_init_psr_http_message_message_interface() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, PSR_HTTP_MESSAGE_NS, "MessageInterface", guzzle_init_psr_http_message_message_interface_method);

    guzzle_psr_http_message_message_interface_ce = zend_register_internal_interface(&ce);

}