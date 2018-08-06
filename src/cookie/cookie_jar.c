//
// Created by 何延龙 on 2018/8/4.
//
#include "php.h"
#include "ext/spl/spl_iterators.h"
#include "zend_interfaces.h"
#include "../common.h"
#include "cookie_jar.h"

zend_class_entry *guzzle_cookie_jar_ce;

ZEND_BEGIN_ARG_INFO_EX(arginfo_clear, 0, 0, 3)
                ZEND_ARG_INFO(0, domain)
                ZEND_ARG_INFO(0, path)
                ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

static zend_function_entry guzzle_cookie_jar_method[] = {
        PHP_ME(CookieJar, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
        PHP_ME(CookieJar, fromArray, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
        PHP_ME(CookieJar, toArray, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(CookieJar, clear, arginfo_clear, ZEND_ACC_PUBLIC)
        PHP_ME(CookieJar, clearSessionCookies, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(CookieJar, setCookie, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(CookieJar, count, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(CookieJar, getIterator, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(CookieJar, extractCookies, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(CookieJar, withCookieHeader, NULL, ZEND_ACC_PUBLIC)
        PHP_FE_END
};

void guzzle_init_cookie_jar() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, GUZZLE_COOKIE_NS, "CookieJar", guzzle_cookie_jar_method);

    guzzle_cookie_jar_ce = zend_register_internal_class(&ce);
    zend_class_implements(guzzle_cookie_jar_ce, 1, guzzle_cookie_jar_interface_ce);

//    zend_declare_property_null(guzzle_cookie_jar_ce, "config", sizeof("config") - 1, ZEND_ACC_PRIVATE);
}

PHP_METHOD (CookieJar, __construct) {

}

PHP_METHOD (CookieJar, fromArray) {}

PHP_METHOD (CookieJar, toArray) {}

PHP_METHOD (CookieJar, clear) {
    char *domain = NULL;
    size_t domain_len;

    char *path = NULL;
    size_t path_len;

    char *name = NULL;
    size_t name_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|sss", &domain, &domain_len, &path, &path_len, &name, &name_len) ==
        FAILURE) {
        return;
    }

    if (!domain) {
        RETURN_NULL();
    } else if (!path) {

        RETURN_STRING("1");
    } else if (!name) {
        RETURN_STRING("2");
    } else {
        RETURN_STRING("3");
    }
}

PHP_METHOD (CookieJar, clearSessionCookies) {}

PHP_METHOD (CookieJar, setCookie) {}

PHP_METHOD (CookieJar, count) {}

PHP_METHOD (CookieJar, getIterator) {}

PHP_METHOD (CookieJar, extractCookies) {}

PHP_METHOD (CookieJar, withCookieHeader) {}