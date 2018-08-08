//
// Created by 何延龙 on 2018/8/6.
//

#ifndef GUZZLE_HANDLER_STACK_H
#define GUZZLE_HANDLER_STACK_H

void guzzle_init_handler_stack();

static PHP_METHOD (HandlerStack, create);

PHP_METHOD (HandlerStack, __construct);

PHP_METHOD (HandlerStack, push);

#endif //GUZZLE_HANDLER_STACK_H
