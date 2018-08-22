//
// Created by 何延龙 on 2018/8/22.
//

#ifndef GUZZLE_PSR_HTTP_MESSAGE_UPLOADED_FILE_INTERFACE_H
#define GUZZLE_PSR_HTTP_MESSAGE_UPLOADED_FILE_INTERFACE_H

void guzzle_init_psr_http_message_uploaded_file_interface();

ZEND_BEGIN_ARG_INFO_EX(arginfo_psr_http_message_uploaded_file_moveTo, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
                ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

#endif //GUZZLE_PSR_HTTP_MESSAGE_UPLOADED_FILE_INTERFACE_H
