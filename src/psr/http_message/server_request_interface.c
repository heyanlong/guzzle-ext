//
// Created by 何延龙 on 2018/8/22.
//

#include "php.h"
#include "../../common.h"
#include "server_request_interface.h"

zend_class_entry *guzzle_psr_http_message_server_request_interface_ce;

static zend_function_entry guzzle_psr_http_message_server_request_interface_method[] = {
        PHP_ABSTRACT_ME(RequestInterface, getServerParams, NULL)
        PHP_ABSTRACT_ME(RequestInterface, getCookieParams, NULL)
        PHP_ABSTRACT_ME(RequestInterface, withCookieParams, arginfo_psr_http_message_server_request_withCookieParams)
        PHP_ABSTRACT_ME(RequestInterface, getQueryParams, NULL)
        PHP_ABSTRACT_ME(RequestInterface, withQueryParams, arginfo_psr_http_message_server_request_withQueryParams)
        PHP_ABSTRACT_ME(RequestInterface, getUploadedFiles, NULL)
        PHP_ABSTRACT_ME(RequestInterface, withUploadedFiles, arginfo_psr_http_message_server_request_withUploadedFiles)
        PHP_ABSTRACT_ME(RequestInterface, getParsedBody, NULL)
        PHP_ABSTRACT_ME(RequestInterface, withParsedBody, arginfo_psr_http_message_server_request_withParsedBody)
        PHP_ABSTRACT_ME(RequestInterface, getAttributes, NULL)
        PHP_ABSTRACT_ME(RequestInterface, getAttribute, arginfo_psr_http_message_server_request_getAttribute)
        PHP_ABSTRACT_ME(RequestInterface, withAttribute, arginfo_psr_http_message_server_request_withAttribute)
        PHP_ABSTRACT_ME(RequestInterface, withoutAttribute, arginfo_psr_http_message_server_request_withoutAttribute)
        PHP_FE_END
};

void guzzle_init_psr_http_message_server_request_interface() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, PSR_HTTP_MESSAGE_NS, "ServerRequestInterface",
                        guzzle_psr_http_message_server_request_interface_method);

    guzzle_psr_http_message_server_request_interface_ce = zend_register_internal_interface(&ce);
    zend_class_implements(guzzle_psr_http_message_server_request_interface_ce, 1,
                          guzzle_psr_http_message_request_interface_ce);
}