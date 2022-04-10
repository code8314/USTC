# CompArch_HW2

PB19111713钟颖康



### 1.

#### a.

| 数据相关类型 | 寄存器 | 源指令 | 目标指令 |
| :----------: | :----: | :----: | :------: |
|     RAW      |   R1   |   ①    |    ②     |
|     WAW      |   R1   |   ①    |    ②     |
|     RAW      |   R1   |   ①    |    ③     |
|     RAW      |   R1   |   ②    |    ③     |
|     WAW      |   R2   |   ①    |    ④     |
|     WAW      |   R2   |   ③    |    ④     |
|     RAW      |   R2   |   ④    |    ⑤     |
|     RAW      |   R4   |   ⑤    |    ⑥     |

#### b.

时序如下表所示：

|       |           |  1   |  2   |   3   |   4   |  5   |   6   |   7   |  8   |  9   |  10   |  11   |  12  |  13   |  14   |  15  |  16  |  17  |  18  |
| :---: | :-------: | :--: | :--: | :---: | :---: | :--: | :---: | :---: | :--: | :--: | :---: | :---: | :--: | :---: | :---: | :--: | :--: | :--: | :--: |
|  LD   | R1,0(R2)  |  IF  |  ID  |  EX   |  MEM  |  WB  |       |       |      |      |       |       |      |       |       |      |      |      |      |
| DADDI | R1,R1,#1  |      |  IF  | stall | stall |  ID  |  EX   |  MEM  |  WB  |      |       |       |      |       |       |      |      |      |      |
|  SD   | R1,0,(R2) |      |      |       |       |  IF  | stall | stall |  ID  |  EX  |  MEM  |  WB   |      |       |       |      |      |      |      |
| DADDI | R2,R2,#4  |      |      |       |       |      |       |       |  IF  |  ID  |  EX   |  MEM  |  WB  |       |       |      |      |      |      |
| DSUB  | R4,R3,R2  |      |      |       |       |      |       |       |      |  IF  | stall | stall |  ID  |  EX   |  MEM  |  WB  |      |      |      |
| BNEZ  |  R4,Loop  |      |      |       |       |      |       |       |      |      |       |       |  IF  | stall | stall |  ID  |  EX  | MEM  |  WB  |
|       |           |      |      |       |       |      |       |       |      |      |       |       |      |       |       |      |      |      |      |
|  LD   | R1,0(R2)  |      |      |       |       |      |       |       |      |      |       |       |      |       |       |      |      |  IF  |  ID  |

所需周期：$98\times 16+18=1586$

#### c.

|       |           |  1   |  2   |  3   |   4   |  5   |  6   |  7   |   8   |  9   |  10  |  11  |  12  |  13  |  14  |  15  |
| :---: | :-------: | :--: | :--: | :--: | :---: | :--: | :--: | :--: | :---: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  LD   | R1,0(R2)  |  IF  |  ID  |  EX  |  MEM  |  WB  |      |      |       |      |      |      |      |      |      |      |
| DADDI | R1,R1,#1  |      |  IF  |  ID  | stall |  EX  | MEM  |  WB  |       |      |      |      |      |      |      |      |
|  SD   | R1,0,(R2) |      |      |  IF  | stall |  ID  |  EX  | MEM  |  WB   |      |      |      |      |      |      |      |
| DADDI | R2,R2,#4  |      |      |      |       |  IF  |  ID  |  EX  |  MEM  |  WB  |      |      |      |      |      |      |
| DSUB  | R4,R3,R2  |      |      |      |       |      |  IF  |  ID  |  EX   | MEM  |  WB  |      |      |      |      |      |
| BNEZ  |  R4,Loop  |      |      |      |       |      |      |  IF  | stall |  ID  |  EX  | MEM  |  WB  |      |      |      |
|       |           |      |      |      |       |      |      |      |       |      |      |      |      |      |      |      |
|  LD   | R1,0(R2)  |      |      |      |       |      |      |      |       |      |      |  IF  |  ID  |  EX  | MEM  |  WB  |

所需周期：$98\times10+12=992$

#### d.

|       |           |  1   |  2   |  3   |   4   |  5   |  6   |  7   |   8   |  9   |  10  |  11  |  12  |  13  |
| :---: | :-------: | :--: | :--: | :--: | :---: | :--: | :--: | :--: | :---: | :--: | :--: | :--: | :--: | :--: |
|  LD   | R1,0(R2)  |  IF  |  ID  |  EX  |  MEM  |  WB  |      |      |       |      |      |      |      |      |
| DADDI | R1,R1,#1  |      |  IF  |  ID  | stall |  EX  | MEM  |  WB  |       |      |      |      |      |      |
|  SD   | R1,0,(R2) |      |      |  IF  | stall |  ID  |  EX  | MEM  |  WB   |      |      |      |      |      |
| DADDI | R2,R2,#4  |      |      |      |       |  IF  |  ID  |  EX  |  MEM  |  WB  |      |      |      |      |
| DSUB  | R4,R3,R2  |      |      |      |       |      |  IF  |  ID  |  EX   | MEM  |  WB  |      |      |      |
| BNEZ  |  R4,Loop  |      |      |      |       |      |      |  IF  | stall |  ID  |  EX  | MEM  |  WB  |      |
|       |           |      |      |      |       |      |      |      |       |      |      |      |      |      |
|  LD   | R1,0(R2)  |      |      |      |       |      |      |      |       |  IF  |  ID  |  EX  | MEM  |  WB  |

所需周期：$98\times8+12=796$



### 2.

时空图如下图所示：

![](figs\HW2-1.jpg)
$$
\begin{aligned}
& 吞吐率 = \frac{7}{18\Delta t}\\
& 加速比 = \frac{29\Delta t}{18\Delta t} \approx1.61 \\
& 效率 = \frac{4\times5+3\times3}{5\times18} \approx0.32 \\
\end{aligned}
$$


### 3.

#### a.仅考虑数据相关时

根据题意易知
$$
CPI_{a-5级流水线}=\frac{6}{5}\\
CPI_{a-12级流水线}=\frac{11}{8}
$$
故
$$
加速比=\frac{I\times CPI_{a-5级流水线}\times1}{I\times CPI_{a-12级流水线}\times0.6}\approx1.45
$$

#### b.考虑分支预测错误导致停顿时

根据题意，
$$
\begin{aligned}
CPI_b & = (20\%\times CPI_a\times95\%+20\%\times(CPI_a+CPI_{cost})\times5\%)+80\%\times CPI_a\\
& = CPI_a+CPI_{cost}\times0.01
\end{aligned}
$$
故
$$
\begin{aligned}
CPI_{b-5级流水线} & = CPI_{a-5级流水线}+CPI_{cost-5级流水线}\times0.01\\
& = 1.22\\
\\
CPI_{b-12级流水线} & = CPI_{a-12级流水线}+CPI_{cost-12级流水线}\times0.01\\
& = 1.425\\
\end{aligned}
$$
