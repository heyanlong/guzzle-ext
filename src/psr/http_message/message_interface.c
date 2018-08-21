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
        PHP_ABSTRACT_ME(MessageInterface, getHeaders, NULL)
        PHP_ABSTRACT_ME(MessageInterface, hasHeader, arginfo_psr_http_message_hasHeader)
        PHP_ABSTRACT_ME(MessageInterface, getHeader, arginfo_psr_http_message_getHeader)
        PHP_ABSTRACT_ME(MessageInterface, getHeaderLine, arginfo_psr_http_message_getHeaderLine)
        PHP_ABSTRACT_ME(MessageInterface, withHeader, arginfo_psr_http_message_withHeader)
        PHP_ABSTRACT_ME(MessageInterface, withAddedHeader, arginfo_psr_http_message_withAddedHeader)
        PHP_ABSTRACT_ME(MessageInterface, withoutHeader, arginfo_psr_http_message_withoutHeader)
        PHP_ABSTRACT_ME(MessageInterface, getBody, NULL)
        PHP_ABSTRACT_ME(MessageInterface, withBody, arginfo_psr_http_message_withBody)
        PHP_FE_END
};

void guzzle_init_psr_http_message_message_interface() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, PSR_HTTP_MESSAGE_NS, "MessageInterface", guzzle_init_psr_http_message_message_interface_method);

    guzzle_psr_http_message_message_interface_ce = zend_register_internal_interface(&ce);

}