<?
    $data = "hi, my baby\n";
    $str = base64_encode($data);
    echo $str;
    $decodeData = base64_decode($str);
    echo $decodeData;