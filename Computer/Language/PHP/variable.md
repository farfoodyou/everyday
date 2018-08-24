PHP支持八种原始类型：
四种标量类型： string（字符串）、integer（整型）、float（浮点型，也作 double 、boolean（布尔型）
两种复合类型：array（数组）、object（对象）
两种特殊类型：resource（资源）、NULL（空）

###### 0 null [] false ''
0是数字，是empty，是false，不是null，值相当于空字符串，但类型不是字符串，去空格或强制转换为字符串型时不等于空字符串
""的值相当于0，是empty，是空字符串，是false，不是null，不是数字字符串
null的值相当于空字符串，值相当于0，是empty，是false，不是字符串，不是数字0
"=="只要值相等就满足条件；　　"==="需要两个变量的值和类型都相等；
strval();将变量转换为字符串类型；
intval();将变量转换为整型；
is_numeric();检测变量是否为数字或数字字符串，返回true或false；

