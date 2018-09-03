<?php
$A = array(
    'name' => 'lisi',
    'age'  => 23,
    'home' => 'hujian',
);
$B = array(
    'name' => 'zhangsan',
    'age'  => 32,
    'home' => 'guangzhou',
);
//array_splice
var_dump(array_slice($A,2,1));
var_dump($A);
var_dump(array_splice($A,2,1,$B));
var_dump($A);