//
// Created by 何延龙 on 2018/8/22.
//

#include "php.h"
#include "../../common.h"
#include "request_interface.h"

zend_class_entry *guzzle_psr_http_message_request_interface_ce;

static zend_function_entry guzzle_init_psr_http_message_request_interface_method[] = {
        PHP_ABSTRACT_ME(RequestInterface, getRequestTarget, NULL)
        PHP_ABSTRACT_ME(RequestInterface, withRequestTarget, arginfo_psr_http_message_request_withRequestTarget)
        PHP_ABSTRACT_ME(RequestInterface, getMethod, NULL)
        PHP_ABSTRACT_ME(RequestInterface, withMethod, arginfo_psr_http_message_request_withMethod)
        PHP_ABSTRACT_ME(RequestInterface, getUri, NULL)
        PHP_ABSTRACT_ME(RequestInterface, withUri, arginfo_psr_http_message_request_withUri)
        PHP_FE_END
};

void guzzle_init_psr_http_message_request_interface() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, PSR_HTTP_MESSAGE_NS, "RequestInterface",
                        guzzle_init_psr_http_message_request_interface_method);

    guzzle_psr_http_message_request_interface_ce = zend_register_internal_interface(&ce);
    zend_class_implements(guzzle_psr_http_message_request_interface_ce, 1,
                          guzzle_psr_http_message_message_interface_ce);

}