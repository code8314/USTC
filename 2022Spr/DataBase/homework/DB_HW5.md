# DB_HW5

PB19111713钟颖康



### Q1：简述事务的性质。

**A1：**

- 原子性
- 一致性
- 隔离性
- 持久性



### Q2：给定关系Student(sno,sname,age,status)。假设所有元组的年龄信息都没有空值，请不要使用聚集函数COUNT、AVG和SUM，自定义一个计算并返回平均年龄的函数aveAge()。

**A2：**

```sql
Create procedure avgAge(out avg INT)
BEGIN
	DECLARE count INT default 0;
	DECLARE sum INT default 0;
	DECLARE s INT default 0;
	DECLARE tmp INT default 0;
	DECLARE StuAge cursor for
		SELECT age FROM Student;
	DECLARE continue Handler for NOT FOUND set s = 1;
	
	OPEN StuAge;
	REPEAT
		FETCH StuAge INTO tmp;
		IF state = 0 THEN
			sum = sum + tmp;
			count = count + 1;
		END IF;
		until s = 1
	end REPEAT;
	CLOSE StuAge;
	avg = sum / count;
END;
```



### Q3：考虑课件第47页所定义的触发器，假设student关系中仅包含两个元组：('001','John',20,'合格')和('002','Mike',22,'合格‘)，并且SC关系一开始为空。现在依次插入下列元组，请问插入哪个元组后，student会被自动更新？

```
a)	('001','c1',74)
b)	('002','c1',45)
c)	('001','c2',55)
d)	('002','c2',58)
e)	('001','c3',88)
f)	('002','c3',37)
g)	('001','c4',43)
h)	('001','c5',29)
```

**A3：**

插入第6列元组后，Mike变为不合格，student自动更新；插入第8列元组后，John变为不合格，student自动更新。



### Q4：请完成课件第49页的触发器实例程序。

**A4：**

```sql
CREAT trigger after_delete
AFTER DELETE ON sc
FOR EACH ROW
BEGIN
	DECLARE course_count INT;
	SELECT count(cno) FROM sc
		WHERE sno = new.sno AND score < 60 INTO course_count;
		
	IF course_count >=3 THEN
		UPDATE student SET Status = '不合格'
			WHERE sno = new.sno
	ELSE
		UPDATE student SET Status = '合格'
			WHERE sno = new.sno
	END IF;
END;
```

