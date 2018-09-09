# 常用函数简介
[TOC]

##### array_map 
```
$res = [];
array_walk($data,function($item)use(&$res){  
    $res[$item['id']] = $item['name'];
});
```
##### array_reduce
array_reduce返回的是一个值
##### array_filter
filter
##### in_array
in
##### + array_merge array_merge_recursive
返回的都是数组
`+` 键值相同取前者， `array_merge` 键值相同取后者 `array_merge_recursive` 键值相同的合并成一个数组作为值

##### sizeof() count()
`sizeof()`和`count()`具有同样的用途，返回数组的长度

##### array_slice() 
`array_slice()` 返回数组的切片


##### is_array()

##### strpos()

##### explode()

##### array_splice()

##### in_array()

