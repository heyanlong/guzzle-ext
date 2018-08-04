<?php
putenv("HTTP_PROXY=cli");
var_dump(new GuzzleHttp\Client(['handler' => 121]));
var_dump(new GuzzleHttp\Client());
?>
