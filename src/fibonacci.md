# Fibonacci Sequence

$$
\left\{
\begin{aligned}
&a_0=1\\
&a_1=1\\
&a_{n+2}=a_{n+1}+a_n\\
\end{aligned}
\right.
$$

## 递推公式

通过递推的方法，循环调用一个函数得到结果

## 备忘录递推公式

由于再递推的时候，多次调用函数，中间会有很有可以重复使用的数据被丢弃了，因此需要在使用的时候，可以定义一个动态存储的单元，动态的存储数据，这样在调用的时候就不用多次重复计算了。

## 动态规划法

我们可以自底而上，依次通过前两个的值来得到后一个的值，直到计算到自己想要的那个值

## 优化动态规划法

在动态规划的时候，因为后一个值只由前两个值来决定，因此并不需要完整的记录下每个值，只需要记录下前两个值即可

## 通项公式法

使用了 fibonacci sequence 的通项公式

$$
a_n = \frac {1} {\sqrt{5}} \left[ \left( \frac {1+\sqrt{5}} {2} \right)^n -\left( \frac {1-\sqrt{5}} {2} \right)^n \right]
$$

直接计算得到结果

缺点

1. 不准确的浮点数运算
2. 求模运算不方便
3. 变体形式需要重新推导

## 矩阵快速幂

这里依然用到了快速幂法，对矩阵依然是生效的

由公式

$$
\begin {aligned}
\begin{bmatrix}
a_n,a_{n+1}
\end {bmatrix}
\cdot
\begin{bmatrix}
0 & 1 \\
1 & 1
\end{bmatrix}
& =
\begin{bmatrix}
a_{n+1},a_n+a_{n+1}
\end{bmatrix}\\
& =
\begin{bmatrix}
a_{n+1},a_{n+2}
\end{bmatrix}
\end {aligned}
$$

此时带入 $n = 1$

$$
\begin{aligned}
\begin{bmatrix}
a_1,a_2
\end{bmatrix}
\cdot
\begin{bmatrix}
0 & 1\\
1 & 1
\end{bmatrix}
\=
\begin{bmatrix}
a_2,a_3
\end{bmatrix}
\end{aligned}
$$

易得

$$
\begin{aligned}
\begin{bmatrix}
a_1,a_2
\end{bmatrix}
\cdot
\begin{bmatrix}
0 & 1\\
1 & 1
\end{bmatrix}^{n-2}
\=
\begin{bmatrix}
a_{n-1},a_{n}
\end{bmatrix}
\end{aligned}
$$
