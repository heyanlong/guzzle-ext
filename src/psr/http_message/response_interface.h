//
// Created by 何延龙 on 2018/8/22.
//

#ifndef GUZZLE_PSR_HTTP_MESSAGE_RESPONSE_INTERFACE_H
#define GUZZLE_PSR_HTTP_MESSAGE_RESPONSE_INTERFACE_H

void guzzle_init_psr_http_message_response_interface();

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_response_withStatus, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, code)
                ZEND_ARG_INFO(0, reasonPhrase)
ZEND_END_ARG_INFO()

#endif //GUZZLE_PSR_HTTP_MESSAGE_RESPONSE_INTERFACE_H
