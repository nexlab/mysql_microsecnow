mysql_microsecnow
=================

Mysql UDF to add a clone of NOW() that return microseconds

After installing it, just execute in the mysql shell:

```
CREATE FUNCTION microsecnow RETURNS INTEGER SONAME 'microsecnow.so';
```

and the you can do:

```
mysql> SELECT MICROSECNOW();
+------------------+
| MICROSECNOW()    |
+------------------+
| 1393634420837085 |
+------------------+
1 row in set (0.00 sec)

mysql> 

```
