# DB_HW6

PB19111713钟颖康



### Q1：假设$\rho$是模式R(A,B,C,D,E)，$\rho$={R1(A,B,C),R2(A,D,E)}，并且R的FD集为：F={A$\rightarrow$BC,CD$\rightarrow$E,B$\rightarrow$D,E$\rightarrow$A}，请证明$\rho$是R的无损分解。

**A1：**

根据题意，$R1\cap R2=\{A\}，R1-R2=\{B,C\}$

根据Q3可知$A\rightarrow ABCDE$

故$(R1\cap R2)\rightarrow (R1-R2)$，$\rho$是R的无损分解。



### Q2：请使用Armstrong公式证明合并律。

**A2：**

不妨设已知$A\rightarrow B,A\rightarrow C$，欲证$A\rightarrow BC$。证明如下：	
$$
\begin{aligned}
& \because A\rightarrow B & \\
& \therefore AA\rightarrow AB & (增广律)\\
& \therefore A\rightarrow AB & \\
& \because A\rightarrow C & \\
& \therefore AB\rightarrow BC & (增广律)\\
& \therefore A\rightarrow BC & (传递律)\\
\end{aligned}
$$


### Q3：请计算Q1中模式R中属性集的闭包：$A^+,B^+,C^+,D^+,E^+,{CD}^+$

**A3：**
$$
\begin{aligned}
\because & A\rightarrow BC & \\
\therefore & A\rightarrow B,A\rightarrow C & (分解律)\\
\because & A\rightarrow B,B\rightarrow D & \\
\therefore & A\rightarrow D & (传递律)\\
\because & A\rightarrow C,A\rightarrow D,CD\rightarrow E & \\
\therefore & A\rightarrow E & (合并律，传递律)\\
\because & A\rightarrow A & (自含律)\\
\therefore & A\rightarrow ABCDE & (合并律)\\
\because & E\rightarrow A & \\
\therefore & E\rightarrow ABCDE & (传递律)\\
\because & CD\rightarrow E & \\
\therefore & CD\rightarrow ABCDE & (传递律)\\
\end{aligned}
$$
故$A^+=\{ABCDE\},B^+=\{BD\},C^+=\{C\},D^+=\{D\},E^+=\{ABCDE\},CD^+=\{ABCDE\},$

### Q4：请给出Q1中模式R的候选码。

**A4：**

结合Q3有
$$
\begin{aligned}
\because & B\rightarrow D & \\
\therefore & BC\rightarrow CD & (增广律)\\
\therefore & BC\rightarrow ABCDE & (传递律)\\
\end{aligned}
$$
易知候选码为$A,BC,CD,E$。



### Q5：Q1中的分解是否保持函数依赖？请证明。

**A5：**

- 不保持函数依赖。
- 显然$\pi_{R_1}(F)=\{A\rightarrow BC\},\pi_{R_2}(F)=\{E\rightarrow A\},(\bigcup_{i=1}^2{\pi_{R_i}})^+\neq F^+$



### Q6：请给出Q1中模式R的一个无损并保持函数依赖的3NF分解。

**A6：**

$\rho_{3NF}=\{(A,B,C),(C,D,E),(B,D),(E,A)\}$

### Q7：请给出Q1中模式R的一个无损的BCNF分解。

**A7：**

$\rho_{BCNF}=\{(A,B,C,E),(B,D)\}$