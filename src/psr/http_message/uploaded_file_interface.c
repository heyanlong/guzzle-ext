//
// Created by 何延龙 on 2018/8/22.
//

#include "php.h"
#include "../../common.h"
#include "uploaded_file_interface.h"

zend_class_entry *guzzle_psr_http_message_uploaded_file_interface_ce;

static zend_function_entry guzzle_psr_http_message_uploaded_file_interface_method[] = {
        PHP_ABSTRACT_ME(UploadedFileInterface, getStream, NULL)
        PHP_ABSTRACT_ME(UploadedFileInterface, moveTo, arginfo_psr_http_message_uploaded_file_moveTo)
        PHP_ABSTRACT_ME(UploadedFileInterface, getSize, NULL)
        PHP_ABSTRACT_ME(UploadedFileInterface, getError, NULL)
        PHP_ABSTRACT_ME(UploadedFileInterface, getClientFilename, NULL)
        PHP_ABSTRACT_ME(UploadedFileInterface, getClientMediaType, NULL)
        PHP_FE_END
};

void guzzle_init_psr_http_message_uploaded_file_interface() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, PSR_HTTP_MESSAGE_NS, "UploadedFileInterface",
                        guzzle_psr_http_message_uploaded_file_interface_method);

    guzzle_psr_http_message_uploaded_file_interface_ce = zend_register_internal_interface(&ce);
}