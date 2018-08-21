<?php
//putenv("HTTP_PROXY=cli");

$client = new GuzzleHttp\Client();

var_dump($client->testCall('1212', [1,2,3,4]));
$a = GuzzleHttp\HandlerStack::create();

var_dump($a);

//$cookie = new GuzzleHttp\Cookie\SetCookie(['Path' => '1213123', "HttpOnly" => true]);

//var_dump($cookie->getSecure());
//var_dump($cookie->getDiscard());
//var_dump($cookie->getHttpOnly());
//var_dump($cookie->setName("11"));
//var_dump($cookie->setValue("kkkk"));
//var_dump($cookie->toArray());
?>
