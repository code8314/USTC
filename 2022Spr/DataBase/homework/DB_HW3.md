# DB_HW3

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

