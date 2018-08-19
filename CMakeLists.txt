cmake_minimum_required(VERSION 3.7)
project(guzzle)

set(CMAKE_CXX_STANDARD 11)
set(PHP_BIN /usr/local/php71/bin)

add_custom_target(makefile COMMAND ${PHP_BIN}/phpize &&
        ./configure --with-php-config=${PHP_BIN}/php-config &&
        $(MAKE) clean && $(MAKE) -j4
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
        guzzle.c
        src/client.c src/client.h
        src/handler_stack.c src/handler_stack.h
        src/cookie/cookie_jar.c src/cookie/cookie_jar.h
        src/cookie/cookie_jar_interface.c src/cookie/cookie_jar_interface.h
        src/cookie/set_cookie.c src/cookie/set_cookie.h
        src/common.h src/middleware.c src/middleware.h)

add_executable(guzzle ${SOURCE_FILES})

set(PHP_SOURCE /usr/local/php71/include/php)
include_directories(${PHP_SOURCE}/main)
include_directories(${PHP_SOURCE}/Zend)
include_directories(${PHP_SOURCE}/sapi)
include_directories(${PHP_SOURCE}/pear)
include_directories(${PHP_SOURCE}/TSRM)
include_directories(${PHP_SOURCE})
include_directories(${PROJECT_SOURCE_DIR})

