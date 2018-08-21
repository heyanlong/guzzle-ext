//
// Created by 何延龙 on 2018/8/21.
//

#ifndef GUZZLE_PSR_HTTP_MESSAGE_MESSAGE_INTERFACE_H
#define GUZZLE_PSR_HTTP_MESSAGE_MESSAGE_INTERFACE_H

void guzzle_init_psr_http_message_message_interface();

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withProtocolVersion, 0, 0, 1)
                ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_hasHeader, 0, 0, 1)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_getHeader, 0, 0, 1)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_getHeaderLine, 0, 0, 1)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withHeader, 0, 0, 2)
                ZEND_ARG_INFO(0, name)
                ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withAddedHeader, 0, 0, 2)
                ZEND_ARG_INFO(0, name)
                ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withoutHeader, 0, 0, 1)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withBody, 0, 0, 1)
                ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

#endif //GUZZLE_PSR_HTTP_MESSAGE_MESSAGE_INTERFACE_H
