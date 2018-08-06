dnl $Id$
dnl config.m4 for extension guzzle

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(guzzle, for guzzle support,
Make sure that the comment is aligned:
[  --with-guzzle             Include guzzle support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(guzzle, whether to enable guzzle support,
dnl Make sure that the comment is aligned:
dnl [  --enable-guzzle           Enable guzzle support])

if test "$PHP_GUZZLE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-guzzle -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/guzzle.h"  # you most likely want to change this
  dnl if test -r $PHP_GUZZLE/$SEARCH_FOR; then # path given as parameter
  dnl   GUZZLE_DIR=$PHP_GUZZLE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for guzzle files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       GUZZLE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$GUZZLE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the guzzle distribution])
  dnl fi

  dnl # --with-guzzle -> add include path
  dnl PHP_ADD_INCLUDE($GUZZLE_DIR/include)

  dnl # --with-guzzle -> check for lib and symbol presence
  dnl LIBNAME=guzzle # you may want to change this
  dnl LIBSYMBOL=guzzle # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $GUZZLE_DIR/$PHP_LIBDIR, GUZZLE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_GUZZLELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong guzzle lib version or lib not found])
  dnl ],[
  dnl   -L$GUZZLE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(GUZZLE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(guzzle, guzzle.c \
  src/client.c \
  src/cookie/cookie_jar.c \
  src/cookie/cookie_jar_interface.c \
  src/cookie/set_cookie.c \
  , $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
