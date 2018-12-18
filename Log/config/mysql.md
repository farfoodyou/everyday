



如下脚本创建数据库yourdbname，并制定默认的字符集是utf8。
CREATE DATABASE IF NOT EXISTS yourdbname DEFAULT CHARSET utf8 COLLATE utf8_general_ci;
如果要创建默认gbk字符集的数据库可以用下面的sql:
create database yourdb DEFAULT CHARACTER SET gbk COLLATE gbk_chinese_ci;


mysql error You must reset your password using ALTER USER statement before executing this statement.
安装完mysql 之后，登陆以后，不管运行任何命令，总是提示这个
step 1: SET PASSWORD = PASSWORD('your new password');
step 2: ALTER USER 'root'@'localhost' PASSWORD EXPIRE NEVER;
step 3: flush privileges;


drop database dbname

CREATE DATABASE IF NOT EXISTS swpdb DEFAULT CHARSET utf8 COLLATE utf8_general_ci;


2018-12-18: 我记得当时这个搞了好几天才成功
