# DB_HW4

PB19111713钟颖康



### Q1：构造下列SQL查询

#### (a)找出2017年其车辆出过交通事故的人员总数

**A1.a**：

```sql
select	count(distinct name)
from	accident,participated,person
where	accident.report_number = participated.report_number
and		participated.driver_id = person.driver_id
and		year = '2017'
```

#### (b)删除ID为"12345"的人拥有的年份为2010的所有汽车

**A1.b**：

```sql
delete	car
where	year = '2010' and license_plate in
	(select license_plate
     from person p, owns o
     where p.driver_id = '12345' and p.driver_id = o.driver_id)
```



### Q2：请写出上述模式的SQL DDL。请在数据类型上作出合理的假设，并确保声明主码和外码。

**A2：**

```sql
creat	table person
		(driver_id	varchar(100),
        name		varchar(100),
        address		varchar(100),
        primary key(driver_id))
```

```sql
creat	table car
		(license_plate	varchar(100),
        model			varchar(100),
        year			integer,
        primary key(license_plate))
```

```sql
creat	table accident
		(report_number	integer,
        year			integer,
        location		varchar(100),
        primary key(report_number))
```

```sql
creat	table owns
		(driver_id		varchar(100),
        license_plate	varchar(100),
        primary key(driver_id,license_plate)
        foreign key(driver_id)references person
        foreign key(license_plate)references car)
```

```sql
creat	table participated
		(report_number	integer,
        license_plate	varchar(100),
        driver_id		varchar(100),
        damage_amount	integer,
        primary key(report_number,license_plate)
        foreign key(report_number)references car
        foreign key(license_plate)references accident)
```



### Q3：SQL支持哪几种约束？我们经常使用的非空约束，属于其中的哪一种？

**A3：**

- 主键约束，唯一键约束，外键约束，检查约束，共四种。
- 非空约束属于检查约束的一种。



### Q4：构造SQL查询：查询没有发生过交通事故的所有人员的姓名。

```sql
(select	name
from person)
except
(select name
from person pe, participated pa
where pa.driver_id = pe.driver_id)
```



### Q5：定义一个视图tot_accident，它给出各地每年发生的事故总数。

```sql
creat view tot_accident
as
	(select count(*)
    from accident
    group by year)
```



### Q6：请问3中定义的视图是否是可更新视图？为什么？

**A6：**

- 不可更新。
- 因为使用了分组操作。

### Q7：请结合视图的作用，谈一谈为什么需要视图？

**A7：**

- 很多时候让用户看到数据库中的所有完整集合并不合适，可能需要向用户隐藏一个关系中的特定数据；
- 此外，我们还需要创建能更好匹配特定用户直观意义上的企业结构，因此需要创建一个“虚拟”关系的个性化集合。