cmake_minimum_required(VERSION 3.7)
project(guzzle)

set(CMAKE_CXX_STANDARD 11)
set(PHP_BIN /usr/local/opt/php71/bin)

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
        src/common.h src/middleware.c src/middleware.h
        src/psr/http_message/message_interface.c src/psr/http_message/message_interface.h
        src/psr/http_message/request_interface.c src/psr/http_message/request_interface.h
        src/psr/http_message/response_interface.c src/psr/http_message/response_interface.h
        src/psr/http_message/server_request_interface.c src/psr/http_message/server_request_interface.h
        src/psr/http_message/stream_interface.c src/psr/http_message/stream_interface.h
        src/psr/http_message/uploaded_file_interface.c src/psr/http_message/uploaded_file_interface.h
        src/psr/http_message/uri_interface.c src/psr/http_message/uri_interface.h)

add_executable(guzzle ${SOURCE_FILES})

set(PHP_SOURCE ${PHP_BIN}/../include/php)
include_directories(${PHP_SOURCE}/main)
include_directories(${PHP_SOURCE}/Zend)
include_directories(${PHP_SOURCE}/sapi)
include_directories(${PHP_SOURCE}/pear)
include_directories(${PHP_SOURCE}/TSRM)
include_directories(${PHP_SOURCE})
include_directories(${PROJECT_SOURCE_DIR})

