<?php
//putenv("HTTP_PROXY=cli");
//var_dump(new GuzzleHttp\Client(['handler' => 121]));
$a = GuzzleHttp\HandlerStack::create();
$a->push(function(){}, "1212");
$a->push(function(){}, "1212");
$a->push(function(){}, "1212");
$a->push(function(){}, "1212");
$a->push(function(){}, "1212");

var_dump($a);

//$cookie = new GuzzleHttp\Cookie\SetCookie(['Path' => '1213123', "HttpOnly" => true]);

//var_dump($cookie->getSecure());
//var_dump($cookie->getDiscard());
//var_dump($cookie->getHttpOnly());
//var_dump($cookie->setName("11"));
//var_dump($cookie->setValue("kkkk"));
//var_dump($cookie->toArray());
?>
