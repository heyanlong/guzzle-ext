//
// Created by 何延龙 on 2018/8/4.
//
#include "php.h"
#include "ext/spl/spl_iterators.h"
#include "zend_interfaces.h"
#include "../common.h"
#include "cookie_jar_interface.h"

zend_class_entry *guzzle_cookie_jar_interface_ce;

ZEND_BEGIN_ARG_INFO_EX(arginfo_withCookieHeader, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_extractCookies, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_setCookie, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_clear, 0, 0, 3)
                ZEND_ARG_INFO(0, domain)
                ZEND_ARG_INFO(0, path)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_clearSessionCookies, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_toArray, 0, 0, 0)
ZEND_END_ARG_INFO()


static zend_function_entry guzzle_cookie_jar_interface_method[] = {
        PHP_ABSTRACT_ME(CookieJarInterface, withCookieHeader, NULL)
        PHP_ABSTRACT_ME(CookieJarInterface, extractCookies, arginfo_extractCookies)
        PHP_ABSTRACT_ME(CookieJarInterface, setCookie, arginfo_setCookie)
        PHP_ABSTRACT_ME(CookieJarInterface, clear, arginfo_clear)
        PHP_ABSTRACT_ME(CookieJarInterface, clearSessionCookies, arginfo_clearSessionCookies)
        PHP_ABSTRACT_ME(CookieJarInterface, toArray, arginfo_toArray)
        PHP_FE_END
};

void guzzle_init_cookie_jar_interface() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, GUZZLE_COOKIE_NS, "CookieJarInterface", guzzle_cookie_jar_interface_method);

    guzzle_cookie_jar_interface_ce = zend_register_internal_interface(&ce);

    zend_class_implements(guzzle_cookie_jar_interface_ce, 2, spl_ce_Countable, zend_ce_aggregate);


}