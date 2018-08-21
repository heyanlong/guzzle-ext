//
// Created by 何延龙 on 2018/8/2.
//

#ifndef GUZZLE_CLIENT_H
#define GUZZLE_CLIENT_H

//
void guzzle_init_client();
//
PHP_METHOD (Client, __construct);

PHP_METHOD (Client, configureDefaults);

PHP_METHOD (Client, __call);

PHP_METHOD(Client, request);

#endif //GUZZLE_CLIENT_H
