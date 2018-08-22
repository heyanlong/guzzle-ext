//
// Created by 何延龙 on 2018/8/22.
//

#include "php.h"
#include "../../common.h"
#include "uri_interface.h"

zend_class_entry *guzzle_psr_http_message_uri_interface_ce;

static zend_function_entry guzzle_psr_http_message_uri_interface_method[] = {
        PHP_ABSTRACT_ME(UriInterface, getScheme, NULL)
        PHP_ABSTRACT_ME(UriInterface, getAuthority, NULL)
        PHP_ABSTRACT_ME(UriInterface, getAuthority, NULL)
        PHP_ABSTRACT_ME(UriInterface, getHost, NULL)
        PHP_ABSTRACT_ME(UriInterface, getPort, NULL)
        PHP_ABSTRACT_ME(UriInterface, getPath, NULL)
        PHP_ABSTRACT_ME(UriInterface, getQuery, NULL)
        PHP_ABSTRACT_ME(UriInterface, getFragment, NULL)
        PHP_ABSTRACT_ME(UriInterface, withScheme, arginfo_psr_http_message_uri_withScheme)
        PHP_ABSTRACT_ME(UriInterface, withUserInfo, arginfo_psr_http_message_uri_withUserInfo)
        PHP_ABSTRACT_ME(UriInterface, withHost, arginfo_psr_http_message_uri_withHost)
        PHP_ABSTRACT_ME(UriInterface, withPort, arginfo_psr_http_message_uri_withPort)
        PHP_ABSTRACT_ME(UriInterface, withPath, arginfo_psr_http_message_uri_withPath)
        PHP_ABSTRACT_ME(UriInterface, withQuery, arginfo_psr_http_message_uri_withQuery)
        PHP_ABSTRACT_ME(UriInterface, withFragment, arginfo_psr_http_message_uri_withFragment)
        PHP_ABSTRACT_ME(UriInterface, __toString, NULL)
        PHP_FE_END
};

void guzzle_init_psr_http_message_uri_interface() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, PSR_HTTP_MESSAGE_NS, "UriInterface",
                        guzzle_psr_http_message_uri_interface_method);

    guzzle_psr_http_message_uri_interface_ce = zend_register_internal_interface(&ce);
}