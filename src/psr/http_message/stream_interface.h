//
// Created by 何延龙 on 2018/8/22.
//

#ifndef GUZZLE_PSR_HTTP_MESSAGE_STREAM_INTERFACE_H
#define GUZZLE_PSR_HTTP_MESSAGE_STREAM_INTERFACE_H

void guzzle_init_psr_http_message_stream_interface();

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_stream_seek, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, offset)
                ZEND_ARG_INFO(0, whence)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_stream_write, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_stream_read, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_stream_getMetadata, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
                ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

#endif //GUZZLE_PSR_HTTP_MESSAGE_STREAM_INTERFACE_H
