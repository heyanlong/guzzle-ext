//
// Created by 何延龙 on 2018/8/21.
//

#ifndef GUZZLE_PSR_HTTP_MESSAGE_MESSAGE_INTERFACE_H
#define GUZZLE_PSR_HTTP_MESSAGE_MESSAGE_INTERFACE_H

void guzzle_init_psr_http_message_message_interface();

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withProtocolVersion, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_hasHeader, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_getHeader, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_getHeaderLine, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withHeader, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
                ZEND_ARG_INFO(0, name)
                ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withAddedHeader, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
                ZEND_ARG_INFO(0, name)
                ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withoutHeader, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withBody, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_OBJ_INFO(0, body, Psr\\Http\\Message\\StreamInterface, 0)
ZEND_END_ARG_INFO()

#endif //GUZZLE_PSR_HTTP_MESSAGE_MESSAGE_INTERFACE_H
