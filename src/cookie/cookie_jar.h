//
// Created by 何延龙 on 2018/8/4.
//

#ifndef GUZZLE_COOKIE_JAR_H
#define GUZZLE_COOKIE_JAR_H

//
void guzzle_init_cookie_jar();
//
PHP_METHOD (CookieJar, __construct);

PHP_METHOD (CookieJar, fromArray);

PHP_METHOD (CookieJar, toArray);

PHP_METHOD (CookieJar, clear);

PHP_METHOD (CookieJar, clearSessionCookies);

PHP_METHOD (CookieJar, setCookie);

PHP_METHOD (CookieJar, count);

PHP_METHOD (CookieJar, getIterator);

PHP_METHOD (CookieJar, extractCookies);

PHP_METHOD (CookieJar, withCookieHeader);

#endif //GUZZLE_COOKIE_JAR_H
