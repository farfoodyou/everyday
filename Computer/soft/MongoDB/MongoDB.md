# MongoDB
Created at 2018/08/14
[TOC]
## 1. Install
install by brew
```
brew install mongodb
```
start
```
mkdir -p /data/db
mongod
```
start with dbpath
```
mongod --dbpath <path to data directory>
```
start with host and porth
```
mongo --host 127.0.0.1:27017
```
use cli
```
mongo
mongodb://admin:123456@localhost/test
```
## 2. 概念解析

|SQL术语/概念|MongoDB术语/概念|解释/说明|
| :------: | :------: | :------ |
|database|database|数据库|
|table	|collection	|数据库表/集合
row	|document	|数据记录行/文档
column	|field	|数据字段/域
index	|index	|索引
table |joins	|表连接,MongoDB不支持
primary |key	|primary key	主键,MongoDB自动将_id字段设置为主键

## 3. DATABASE AND COLLECTIONS
create/drop database
```
use DATABASE_NAME
db.dropDatabase()
```
create/drop collection
```
db.createCollection(name, options)
db.collection.createIndex(keys, options)
db.collection.drop()

db.hu.createIndex({"title":1})
```

show
```
show dbs
show collections
db.COLLECTION_NAME.find()
db.COLLECTION_NAME.find().pretty()
```

insert/save
```
db.COLLECTION_NAME.insert(document)
db.COLLECTION_NAME.save(document)
```


update
```
db.collection.update(
   <query>,
   <update>,
   {
     upsert: <boolean>,
     multi: <boolean>,
     writeConcern: <document>
   }
)

db.collection.remove(
   <query>,
   {
     justOne: <boolean>,
     writeConcern: <document>
   }
)
```
db.hu.insert({"name":"hu"})

## MongoDB 与 RDBMS Where 语句比较
操作	|格式	|范例	|RDBMS中的类似语句
--|-------|-------|------
等于	|{key:value}	|db.col.find({"by":"教程"}).pretty()	|where by = '教程'
小于	|{key:{$lt:value}}	|db.col.find({"likes":{$lt:50}}).pretty()	|where likes < 50
小于等于	|{key:{$lte:value}}	|db.col.find({"likes":{$lte:50}}).pretty()	|where likes <= 50
大于	|{key:{$gt:value}}	|db.col.find({"likes":{$gt:50}}).pretty()	|where likes > 50
大于等于	|{key:{$gte:value}}	|db.col.find({"likes":{$gte:50}}).pretty()	|where likes >= 50
不等于	|{key:{$ne:value>}	|db.col.find({"likes":{$ne:50}}).pretty()	|where likes != 50

```
$gt -------- greater than  >
$gte --------- gt equal  >=
$lt -------- less than  <
$lte --------- lt equal  <=
$ne ----------- not equal  !=
$eq  --------  equal  =
```

## sort
```
db.COLLECTION_NAME.find().sort({KEY:1})
```