//
// Created by 何延龙 on 2018/8/4.
//

#ifndef GUZZLE_SET_COOKIE_H
#define GUZZLE_SET_COOKIE_H

void guzzle_init_set_cookie();

PHP_METHOD (SetCookie, fromString);

PHP_METHOD (SetCookie, __construct);

PHP_METHOD (SetCookie, __toString);

PHP_METHOD (SetCookie, toArray);

PHP_METHOD (SetCookie, getName);

PHP_METHOD (SetCookie, setName);

PHP_METHOD (SetCookie, getValue);

PHP_METHOD (SetCookie, setValue);

PHP_METHOD (SetCookie, getDomain);

PHP_METHOD (SetCookie, setDomain);

PHP_METHOD (SetCookie, getPath);

PHP_METHOD (SetCookie, setPath);

PHP_METHOD (SetCookie, getMaxAge);

PHP_METHOD (SetCookie, setMaxAge);

PHP_METHOD (SetCookie, getExpires);

PHP_METHOD (SetCookie, setExpires);

PHP_METHOD (SetCookie, getSecure);

PHP_METHOD (SetCookie, setSecure);

PHP_METHOD (SetCookie, getDiscard);

PHP_METHOD (SetCookie, setDiscard);

PHP_METHOD (SetCookie, getHttpOnly);

PHP_METHOD (SetCookie, setHttpOnly);

#endif //GUZZLE_SET_COOKIE_H
