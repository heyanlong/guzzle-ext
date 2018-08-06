//
// Created by 何延龙 on 2018/8/4.
//

#include "php.h"
#include "../common.h"
#include "set_cookie.h"
#include "ext/standard/php_var.h"
#include "Zend/zend_interfaces.h"
#include "time.h"

zend_class_entry *guzzle_set_cookie_ce;

static zend_function_entry guzzle_init_set_cookie_method[] = {


        PHP_ME(SetCookie, fromString, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)

        PHP_ME(SetCookie, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)

        PHP_ME(SetCookie, __toString, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, toArray, NULL, ZEND_ACC_PUBLIC)

        PHP_ME(SetCookie, getName, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, setName, NULL, ZEND_ACC_PUBLIC)

        PHP_ME(SetCookie, getValue, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, setValue, NULL, ZEND_ACC_PUBLIC)

        PHP_ME(SetCookie, getDomain, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, setDomain, NULL, ZEND_ACC_PUBLIC)

        PHP_ME(SetCookie, getPath, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, setPath, NULL, ZEND_ACC_PUBLIC)

        PHP_ME(SetCookie, getMaxAge, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, setMaxAge, NULL, ZEND_ACC_PUBLIC)

        PHP_ME(SetCookie, getExpires, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, setExpires, NULL, ZEND_ACC_PUBLIC)

        PHP_ME(SetCookie, getSecure, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, setSecure, NULL, ZEND_ACC_PUBLIC)

        PHP_ME(SetCookie, getDiscard, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, setDiscard, NULL, ZEND_ACC_PUBLIC)

        PHP_ME(SetCookie, getHttpOnly, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(SetCookie, setHttpOnly, NULL, ZEND_ACC_PUBLIC)
};

void guzzle_init_set_cookie() {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, GUZZLE_COOKIE_NS, "SetCookie", guzzle_init_set_cookie_method);

    guzzle_set_cookie_ce = zend_register_internal_class(&ce);


    zend_declare_property_null(guzzle_set_cookie_ce, ZEND_STRL("defaults"), ZEND_ACC_PRIVATE | ZEND_ACC_STATIC);
    zend_declare_property_null(guzzle_set_cookie_ce, ZEND_STRL("data"), ZEND_ACC_PRIVATE);

}

PHP_METHOD (SetCookie, fromString) {

}

PHP_METHOD (SetCookie, __construct) {
    zval defaults;
    array_init(&defaults);

    zval name;
    zval value;
    zval domain;
    zval path;
    zval max_age;
    zval expires;
    zval source;
    zval discard;
    zval http_only;
    ZVAL_NULL(&name);
    ZVAL_NULL(&value);
    ZVAL_NULL(&domain);
    ZVAL_STRINGL(&path, "/", sizeof("/") - 1);
    ZVAL_NULL(&max_age);
    ZVAL_NULL(&expires);
    ZVAL_BOOL(&source, 0);
    ZVAL_BOOL(&discard, 0);
    ZVAL_BOOL(&http_only, 0);
    zend_hash_add(Z_ARRVAL_P(&defaults), zend_string_init("Name", sizeof("Name") - 1, 0), &name);
    zend_hash_add(Z_ARRVAL_P(&defaults), zend_string_init("Value", sizeof("Value") - 1, 0), &value);
    zend_hash_add(Z_ARRVAL_P(&defaults), zend_string_init("Domain", sizeof("Domain") - 1, 0), &domain);
    zend_hash_add(Z_ARRVAL_P(&defaults), zend_string_init("Path", sizeof("Path") - 1, 0), &path);
    zend_hash_add(Z_ARRVAL_P(&defaults), zend_string_init("Max-Age", sizeof("Max-Age") - 1, 0), &max_age);
    zend_hash_add(Z_ARRVAL_P(&defaults), zend_string_init("Expires", sizeof("Expires") - 1, 0), &expires);
    zend_hash_add(Z_ARRVAL_P(&defaults), zend_string_init("Secure", sizeof("Secure") - 1, 0), &source);
    zend_hash_add(Z_ARRVAL_P(&defaults), zend_string_init("Discard", sizeof("Discard") - 1, 0), &discard);
    zend_hash_add(Z_ARRVAL_P(&defaults), zend_string_init("HttpOnly", sizeof("HttpOnly") - 1, 0), &http_only);

    zend_update_static_property(guzzle_set_cookie_ce, ZEND_STRL("defaults"), &defaults);

    zval *data;
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "|a", &data) == FAILURE) {
        return;
    }

    zval retval;
    zval fname;
    zval zp[2];
    ZVAL_ARR(&zp[0], Z_ARRVAL_P(&defaults));

    if (data && IS_ARRAY == Z_TYPE_P(data)) {
        ZVAL_ARR(&zp[1], Z_ARRVAL_P(data));
    } else {
        zval temp;
        array_init(&temp);
        ZVAL_ARR(&zp[1], Z_ARRVAL_P(&temp));
    }

    ZVAL_STR(&fname, zend_string_init("array_replace", sizeof("array_replace") - 1, 0));

    call_user_function(EG(function_table), NULL, &fname, &retval, 2, zp);

    zend_update_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), &retval);

    zval _expires;
    zval _max_age;
    zend_call_method(getThis(), guzzle_set_cookie_ce, NULL, ZEND_STRL("getexpires"), &_expires, 0, NULL, NULL);
    zend_call_method(getThis(), guzzle_set_cookie_ce, NULL, ZEND_STRL("getmaxage"), &_max_age, 0, NULL, NULL);

    if (IS_NULL == Z_TYPE_P(&_expires) && IS_NULL != Z_TYPE_P(&_max_age)) {

        zval set_expire;
        ZVAL_LONG(&set_expire, time(NULL) + _max_age.value.lval);

        zend_call_method(getThis(), guzzle_set_cookie_ce, NULL, ZEND_STRL("setexpires"), NULL, 1, &set_expire, NULL);
    } else if (IS_NULL != Z_TYPE_P(&_expires) && IS_LONG != Z_TYPE_P(&_expires)) {
        zend_call_method(getThis(), guzzle_set_cookie_ce, NULL, ZEND_STRL("setexpires"), NULL, 1, &_expires, NULL);
    }

}

PHP_METHOD (SetCookie, __toString) {

}

PHP_METHOD (SetCookie, toArray) {
    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);
    RETURN_ARR(data->value.arr);
}

PHP_METHOD (SetCookie, getName) {
    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);
    zval *value = zend_hash_str_find(Z_ARRVAL_P(data), ZEND_STRL("Name"));
    RETURN_STR(value->value.str);

}

PHP_METHOD (SetCookie, setName) {
    zend_string *name;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &name) == FAILURE) {
        return;
    }

    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 1, NULL);
    zval tmp;
    ZVAL_STR(&tmp, name);

    zend_hash_update(Z_ARRVAL_P(data), zend_string_init("Name", sizeof("Name") - 1, 0), &tmp);
    zend_update_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), data);

}

PHP_METHOD (SetCookie, getValue) {
    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);
    zval *value = zend_hash_str_find(Z_ARRVAL_P(data), ZEND_STRL("Value"));
    RETURN_STR(value->value.str);
}

PHP_METHOD (SetCookie, setValue) {
    zend_string *value;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "S", &value) == FAILURE) {
        return;
    }

    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 1, NULL);
    zval tmp;
    ZVAL_STR(&tmp, value);

    zend_hash_update(Z_ARRVAL_P(data), zend_string_init("Value", sizeof("Value") - 1, 0), &tmp);
    zend_update_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), data);
}

PHP_METHOD (SetCookie, getDomain) {
    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);
    zval *value = zend_hash_str_find(Z_ARRVAL_P(data), ZEND_STRL("Domain"));

    if (value && IS_NULL == Z_TYPE_P(value)) {
        RETURN_NULL();
    }
    RETURN_STR(value->value.str);
}

PHP_METHOD (SetCookie, setDomain) {}

PHP_METHOD (SetCookie, getPath) {

    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);
    zval *value = zend_hash_str_find(Z_ARRVAL_P(data), ZEND_STRL("Path"));

    if (value) {
        RETURN_STR(value->value.str);
    }
    RETURN_NULL();
}

PHP_METHOD (SetCookie, setPath) {}

PHP_METHOD (SetCookie, getMaxAge) {
    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);


    zval *max_age = zend_hash_str_find(Z_ARRVAL_P(data), "Max-Age", sizeof("Max-Age") - 1);

    int type = Z_TYPE_P(max_age);

    if (IS_NULL == type) {
        RETURN_NULL();
    } else if (IS_LONG == type) {
        RETURN_LONG(max_age->value.lval);
    }
}

PHP_METHOD (SetCookie, setMaxAge) {

}

PHP_METHOD (SetCookie, getExpires) {

    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);
    zval *value = zend_hash_str_find(Z_ARRVAL_P(data), ZEND_STRL("Expires"));

    if (value && IS_LONG == Z_TYPE_P(value)) {
        RETURN_LONG(value->value.lval);
    }
    RETURN_NULL();
}

PHP_METHOD (SetCookie, setExpires) {
    zval *timestamp;

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "z", &timestamp) == FAILURE) {
        return;
    }

    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);

    if (IS_LONG == Z_TYPE_P(timestamp)) {
        zend_hash_update(Z_ARRVAL_P(data), zend_string_init("Expires", sizeof("Expires") - 1, 0), timestamp);
        zend_update_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), data);
    } else {
        // todo strtotime
//        zend_hash_update(Z_ARRVAL_P(data), zend_string_init("Expires", sizeof("Expires") - 1, 0), timestamp);
//        zend_update_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), data);
    }

}

PHP_METHOD (SetCookie, getSecure) {

    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);
    zval *value = zend_hash_str_find(Z_ARRVAL_P(data), ZEND_STRL("Secure"));

    if (!value) {
        RETURN_NULL();
    } else if (IS_TRUE == Z_TYPE_P(value)) {
        RETURN_BOOL(1);
    } else if (IS_TRUE != Z_TYPE_P(value)) {
        RETURN_BOOL(0);
    }
}

PHP_METHOD (SetCookie, setSecure) {}

PHP_METHOD (SetCookie, getDiscard) {
    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);
    zval *value = zend_hash_str_find(Z_ARRVAL_P(data), ZEND_STRL("Discard"));

    if (!value) {
        RETURN_NULL();
    } else if (IS_TRUE == Z_TYPE_P(value)) {
        RETURN_BOOL(1);
    } else if (IS_TRUE != Z_TYPE_P(value)) {
        RETURN_BOOL(0);
    }
}

PHP_METHOD (SetCookie, setDiscard) {}

PHP_METHOD (SetCookie, getHttpOnly) {
    zval *data = zend_read_property(guzzle_set_cookie_ce, getThis(), ZEND_STRL("data"), 0, NULL);
    zval *value = zend_hash_str_find(Z_ARRVAL_P(data), ZEND_STRL("HttpOnly"));

    if (!value) {
        RETURN_NULL();
    } else if (IS_TRUE == Z_TYPE_P(value)) {
        RETURN_BOOL(1);
    } else if (IS_TRUE != Z_TYPE_P(value)) {
        RETURN_BOOL(0);
    }
}

PHP_METHOD (SetCookie, setHttpOnly) {}