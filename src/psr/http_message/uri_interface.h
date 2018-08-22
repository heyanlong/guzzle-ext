//
// Created by 何延龙 on 2018/8/22.
//

#ifndef GUZZLE_PSR_HTTP_MESSAGE_URI_INTERFACE_H
#define GUZZLE_PSR_HTTP_MESSAGE_URI_INTERFACE_H

void guzzle_init_psr_http_message_uri_interface();

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_uri_withScheme, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_uri_withUserInfo, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, user)
                ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_uri_withHost, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, host)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_uri_withPort, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_uri_withPath, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_uri_withQuery, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, query)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_uri_withFragment, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, fragment)
ZEND_END_ARG_INFO()

#endif //GUZZLE_PSR_HTTP_MESSAGE_URI_INTERFACE_H
