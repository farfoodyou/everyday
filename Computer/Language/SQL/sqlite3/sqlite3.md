##
好久没用过SQL了.
现在又复习了一遍
#### open and quit
sqlite3
.quit

### table
#### create
create table1(
    id int primary not null,
    name text not null,
    content text not null
);
#### drop
drop table test;

#### alter
ALTER TABLE database_name.table_name RENAME TO new_table_name;
ALTER TABLE database_name.table_name ADD COLUMN column_def...;

#### test
drop table test;
create table test (
    [tkid]            integer PRIMARY KEY autoincrement,                -- 设置主键
    [tktype]          int default 0,
    [tableid]         varchar (50),
    [createdate]      datetime default (datetime('now', 'localtime'))    -- 时间
);
### record
#### insert
insert into table1
(t1, t2, t3, t4)
value (v1, v2, b3, v4);

#### select
select * from table1;

#### update
update table1
set t1 = v1, t2 = v2, t3 = v3
where id = 233;

#### delete
delete from table1
where id = 233;

#### like
select * from task 
where content like '%in%r_';

#### limit
select * from task
where con

#### order by
SELECT column-list 
FROM table_name 
[WHERE condition] 
[ORDER BY column1, column2, .. columnN] [ASC | DESC];

#### group by
SELECT column-list
FROM table_name
WHERE [ conditions ]
GROUP BY column1, column2....columnN
ORDER BY column1, column2....columnN

#### having
SELECT column1, column2
FROM table1, table2
WHERE [ conditions ]
GROUP BY column1, column2
HAVING [ conditions ]
ORDER BY column1, column2

#### distinct
SELECT DISTINCT column1, column2,.....columnN 
FROM table_name
WHERE [ condition ]

#### join
##### inner join
SELECT EMP_ID, NAME, DEPT FROM COMPANY INNER JOIN DEPARTMENT
        ON COMPANY.ID = DEPARTMENT.EMP_ID;
SELECT ... FROM table1 JOIN table2 USING ( column1 ,... ) ...
##### cross join
SELECT EMP_ID, NAME, DEPT FROM COMPANY CROSS JOIN DEPARTMENT;
##### outer join

##### UNION
SELECT column1 [, column2 ]
FROM table1 [, table2 ]
[WHERE condition]

UNION

SELECT column1 [, column2 ]
FROM table1 [, table2 ]
[WHERE condition]

##### as
SELECT column_name AS alias_name
FROM table_name
WHERE [condition];

##### TRANSACTION
```
BEGIN;
or 
BEGIN TRANSACTION;
```

```
COMMIT;
or
END TRANSACTION;
```

```
ROLLBACK;
```
##### AUTOINCREMENT
CREATE TABLE table_name(
   column1 INTEGER AUTOINCREMENT,
   column2 datatype,
   column3 datatype,
   .....
   columnN datatype,
);

