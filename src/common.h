//
// Created by 何延龙 on 2018/8/4.
//

#ifndef GUZZLE_COMMON_H
#define GUZZLE_COMMON_H

#define GUZZLE_NS "GuzzleHttp"
#define GUZZLE_COOKIE_NS "GuzzleHttp\\Cookie"
#define PSR_HTTP_MESSAGE_NS "Psr\\Http\\Message"

extern zend_class_entry *guzzle_client_ce;
extern zend_class_entry *guzzle_cookie_jar_ce;
extern zend_class_entry *guzzle_set_cookie_ce;
extern zend_class_entry *guzzle_cookie_jar_interface_ce;
extern zend_class_entry *guzzle_handler_stack_ce;
extern zend_class_entry *guzzle_middleware_ce;
extern zend_class_entry *guzzle_psr_http_message_message_interface_ce;


#endif //GUZZLE_COMMON_H
