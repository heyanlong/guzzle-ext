//
// Created by 何延龙 on 2018/8/2.
//

#ifndef GUZZLE_CLIENT_H
#define GUZZLE_CLIENT_H

#define GUZZLE_NS "GuzzleHttp"

extern zend_class_entry *guzzle_client_ce;
//
void guzzle_init_client();
//
PHP_METHOD (Client, __construct);
PHP_METHOD (Client, configureDefaults);

#endif //GUZZLE_CLIENT_H
