cmake_minimum_required(VERSION 3.7)
project(guzzle)

set(CMAKE_CXX_STANDARD 11)

add_custom_target(makefile COMMAND /usr/local/opt/php@7.1/bin/phpize &&
        ./configure --with-php-config=/usr/local/opt/php@7.1/bin/php-config &&
        $(MAKE) clean && $(MAKE)
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
        guzzle.c
        src/client.c src/client.h
        src/cookie/cookie_jar.c src/cookie/cookie_jar.h
        src/cookie/cookie_jar_interface.c src/cookie/cookie_jar_interface.h
        src/cookie/set_cookie.c src/cookie/set_cookie.h
        src/common.h)

add_executable(guzzle ${SOURCE_FILES})

set(PHP_SOURCE /usr/local/opt/php@7.1/include/php)
include_directories(${PHP_SOURCE}/main)
include_directories(${PHP_SOURCE}/Zend)
include_directories(${PHP_SOURCE}/sapi)
include_directories(${PHP_SOURCE}/pear)
include_directories(${PHP_SOURCE}/TSRM)
include_directories(${PHP_SOURCE})
include_directories(${PROJECT_SOURCE_DIR})

