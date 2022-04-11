# DB_HW1

PB19111713钟颖康



### Q1：将数据保存在文件系统中有哪些缺点？

**A1：**

- 可能存在数据冗余和一致性问题、完整性问题、共享和并发访问问题、安全性问题等。



### Q2： 列出四个你使用过的、很可能使用了数据库来存储持久数据的应用。

**A2：**

- QQ，教务系统，支付宝，钉钉。



### Q3：数据库的基本特征是什么？

**A3：**

- 持久存储；数据按一定的数据模型组织、描述和存储；可为各种用户共享；数据间联系密切，具有最小冗余和较高的独立性；服务于某个特定的应用。



### Q4：什么是DBMS？DBMS的功能有哪些？

**A4：**

- DBMS指数据库管理系统，是计算机程序的集合，用于创建和维护数据库。

- 功能主要包括数据库定义、操纵、保护、建立和维护。




### Q5：列出为一个企业建立数据库的六个主要步骤。

**A5：**

1. 需求分析；
2. 概念设计；

3. 逻辑设计；

4. 物理设计；

5. 数据库实施；

6. 数据库运行于维护。



# HW2

PB19111713钟颖康



### Q1：什么是粗粒度并行？什么是细粒度并行？两者的区别是什么？

**A1：**

- 粗粒度并行是指在每个处理器上各自运行一个查询。

- 细粒度并行是指单个查询被划分到多个处理器上并行执行。

- 区别是处理器运行的查询数量不同。



### Q2：解释两层体系结构和三层体系结构之间的区别？

**A2：**

- 相较于两层体系结构，三层体系结构的业务逻辑层从客户端分离出来了。




### Q3：分布式数据库的特点是什么？

**A3：**

- 数据物理分布、逻辑统一；局部自治；共享数据。




### Q4：什么是数据独立性？它们的作用分别是什么？

**A4：**

- 数据独立性包括物理独立性和逻辑独立性，其中物理独立性是指用户的应用与数据库中的数据是独立的，逻辑独立性是指用户的应用程序与数据库的逻辑结构相互独立。

- 当数据库的内部存储结构发生改变时，只要修改模式/内模式映象，可保可保持概念模式不变，从而保持外模式以及用户程序的不变，保证了数据与程序的物理独立性；当概念模式发生改变时，只要修改外模式/模式映象，可保持外模式不变，从而保持用户应用程序不变，保证了数据与用户程序的逻辑独立性。



# HW3

PB19111713钟颖康



### Q1：数据模型有哪三个要素？哪三个层次？

**A1：**

- 数据结构，数据操作，数据的完整性约束。
- 概念数据模型，逻辑数据模型，物理数据模型。



### Q2：关系模型中主码的含义是什么？主码只能是一个属性吗？若不是，请举例说明。

**A2：**

- 用户选作元组标识的那个候选码称为主码。
- 可以不止一个属性。例：classroom(building, room_number, capacity)，主码是(building, room_number)，含有两个属性。



### Q3：关系模型有哪三类完整性规则？

**A3：**

- 实体完整性，参照完整性，用户自定义完整性。



### Q4：分析关系代数部分的ppt第27页的三个表达式。

**A4：**

7：

- 所有零件的零件号：$\pi_{P\#}(P)$
- 所有供应关系：$\pi_{S\#,P\#}(SP)$
- 提供所有零件的供应商的商号：$\pi_{S\#,P\#}(SP)÷\pi_{P\#}(P)$
- 提供所有零件的供应商的所有信息：$S⋈(\pi_{S\#,P\#}(SP)÷\pi_{P\#}(P))$
- 提供所有零件的供应商的名字：$\pi_{SNAME}(S⋈(\pi_{S\#,P\#}(SP)÷\pi_{P\#}(P)))$

8：

- S2提供的所有零件的零件号：$\pi_{P\#}(\sigma_{S\#='S2'}(SP))$
- 所有供应关系：$\pi_{S\#,P\#}(SP)$
- 提供了S2提供的所有零件的供应商的商号：$\pi_{S\#,P\#}(SP)÷\pi_{P\#}(\sigma_{S\#='S2'}(SP))$
- 提供了S2提供的所有零件的供应商的所有信息：$S⋈(\pi_{S\#,P\#}(SP)÷\pi_{P\#}(\sigma_{S\#='S2'}(SP)))$
- 提供了S2提供的所有零件的供应商的名字：$\pi_{SNAME}(S⋈(\pi_{S\#,P\#}(SP)÷\pi_{P\#}(\sigma_{S\#='S2'}(SP))))$

9：

- 包含供应商所有信息的供应关系：$S⋈SP$
- 提供零件P2的供应商的所有信息：$\sigma_{P\#='P2'}(S⋈SP)$
- 提供零件P2的供应商名：$\pi_{SNAME}(\sigma_{P\#='P2'}(S⋈SP))$
- 不提供零件P2的供应商名：$\pi_{SNAME}(S)-\pi_{SNAME}(\sigma_{P\#='P2'}(S⋈SP))$
