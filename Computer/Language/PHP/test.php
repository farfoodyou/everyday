<?php
    echo "hi\n";
    $boy = array(
        'name' => 'lisi'
    );
    //var_dump($boy);

    echo "请输入内容:";
    $jimmy = fgets(STDIN);
    echo sprintf("输入的内容为: %s\n", $jimmy);
    
    $demo = fopen('php://stdin', 'r');
    echo "请输入: ";
    $test = fread($demo, 12); //最多读取12个字符
    echo sprintf("输入为: %s\n", $test);
    fclose($demo);

    $x=0;
    while($x!=42){
        $x = fgets(STDIN);
        if($x!=42){
        echo sprintf("%d\n",$x);
        }
    }
?>