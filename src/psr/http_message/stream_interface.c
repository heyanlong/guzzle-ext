//
// Created by 何延龙 on 2018/8/22.
//

#include "php.h"
#include "../../common.h"
#include "stream_interface.h"

zend_class_entry *guzzle_psr_http_message_stream_interface_ce;

static zend_function_entry guzzle_psr_http_message_stream_interface_method[] = {
        PHP_ABSTRACT_ME(StreamInterface, __toString, NULL)
        PHP_ABSTRACT_ME(StreamInterface, close, NULL)
        PHP_ABSTRACT_ME(StreamInterface, detach, NULL)
        PHP_ABSTRACT_ME(StreamInterface, getSize, NULL)
        PHP_ABSTRACT_ME(StreamInterface, tell, NULL)
        PHP_ABSTRACT_ME(StreamInterface, eof, NULL)
        PHP_ABSTRACT_ME(StreamInterface, isSeekable, NULL)
        PHP_ABSTRACT_ME(StreamInterface, seek, arginfo_psr_http_message_stream_seek)
        PHP_ABSTRACT_ME(StreamInterface, rewind, NULL)
        PHP_ABSTRACT_ME(StreamInterface, isWritable, NULL)
        PHP_ABSTRACT_ME(StreamInterface, write, arginfo_psr_http_message_stream_write)
        PHP_ABSTRACT_ME(StreamInterface, isReadable, NULL)
        PHP_ABSTRACT_ME(StreamInterface, read, arginfo_psr_http_message_stream_read)
        PHP_ABSTRACT_ME(StreamInterface, getContents, NULL)
        PHP_ABSTRACT_ME(StreamInterface, getMetadata, arginfo_psr_http_message_stream_getMetadata)
        PHP_FE_END
};

void guzzle_init_psr_http_message_stream_interface() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, PSR_HTTP_MESSAGE_NS, "StreamInterface", guzzle_psr_http_message_stream_interface_method);

    guzzle_psr_http_message_stream_interface_ce = zend_register_internal_interface(&ce);
}