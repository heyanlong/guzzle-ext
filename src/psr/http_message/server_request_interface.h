//
// Created by 何延龙 on 2018/8/22.
//

#ifndef GUZZLE_PSR_HTTP_MESSAGE_SERVER_REQUEST_INTERFACE_H
#define GUZZLE_PSR_HTTP_MESSAGE_SERVER_REQUEST_INTERFACE_H

void guzzle_init_psr_http_message_server_request_interface();

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_server_request_withCookieParams, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_ARRAY_INFO(0, cookies, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_server_request_withQueryParams, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_ARRAY_INFO(0, query, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_server_request_withUploadedFiles, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE,
                       1)
                ZEND_ARG_ARRAY_INFO(0, uploadedFiles, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_server_request_withParsedBody, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, parsedBody)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_server_request_getAttribute, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, name)
                ZEND_ARG_INFO(0, default)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_server_request_withAttribute, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
                ZEND_ARG_INFO(0, name)
                ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_server_request_withoutAttribute, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#endif //GUZZLE_PSR_HTTP_MESSAGE_SERVER_REQUEST_INTERFACE_H
