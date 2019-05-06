苦于关联两条日志没有合适的办法, 结果找到了q
能够使用数据库一样查询文件的内容.

join -1 1 -2 1 log1 log2

import sqlite3


q "select * from t1 t join emails e on (t.c3 == e.c1)" 

q "select * from t1 t left join emails e on (t.c3 == e.c1)" 