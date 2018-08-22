//
// Created by 何延龙 on 2018/8/22.
//

#ifndef GUZZLE_PSR_HTTP_MESSAGE_REQUEST_INTERFACE_H
#define GUZZLE_PSR_HTTP_MESSAGE_REQUEST_INTERFACE_H

void guzzle_init_psr_http_message_request_interface();

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_request_withRequestTarget, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, requestTarget)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_request_withMethod, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_request_withUri, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_OBJ_INFO(0, logger, Psr\\Http\\Message\\UriInterface, 0)
                ZEND_ARG_INFO(0, preserveHost)
ZEND_END_ARG_INFO()

#endif //GUZZLE_PSR_HTTP_MESSAGE_REQUEST_INTERFACE_H
