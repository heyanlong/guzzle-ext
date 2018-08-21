//
// Created by 何延龙 on 2018/8/21.
//

#ifndef GUZZLE_PSR_HTTP_MESSAGE_MESSAGE_INTERFACE_H
#define GUZZLE_PSR_HTTP_MESSAGE_MESSAGE_INTERFACE_H

void guzzle_init_psr_http_message_message_interface();

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_withProtocolVersion, 0, 0, 1)
                ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

#endif //GUZZLE_PSR_HTTP_MESSAGE_MESSAGE_INTERFACE_H
