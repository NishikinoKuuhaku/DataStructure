# 课下作业题 01

## 说明

本次作业共 5 道编程题目，DDL 时间为 `2020-02-21 24:00` 。

请使用提供的代码模板编写、调试与提交代码。

## 01 - 复数运算

我们把形如 `z = a + bi`（ `a,b` 均为实数）的数称为复数，其中 `a` 称为实部，`b` 称为虚部，`i` 称为虚数单位。有：

$$
\sqrt{-1} = i \\ i*i = -1
$$

现在给你两个复数 `A = a1 + a2i, B = b1 + b2i` ，和一个加减乘除内的运算符，要求你实现这两个复数的运算

### 输入

- 四个 `int` 类型的变量，分别代表 `a1,a2,b1,b2`
- 一个 `char` 类型的变量，属于加减乘除操作中的一种 （即 `'+','-','*','/'`）
- 保证输入都是可运算的

### 输出（保存在 `dest` 参数中）

- 两个 `double` 类型的变量（以一个数组形式输出），表示复数 `A, B` 经过该操作符后的结果

### 样例

#### 输入样例

按 `a1 - a2 - b1 - b2 - act` 顺序

```
1 2 3 4 +
1 0 0 2 *
```

#### 输出案例

```
4.00 6.00
0.00 2.00
```

### 考点

- 基本程序逻辑

---

## 02 - 编辑字符串（插入）

请你试图将一个字符串插入在另一个字符串的指定位置上

### 输入

- 两个字符串数组 `base, insert`
- 一个 `int` 类型的正整数 `pos`
- 保证输入的内容不会造成 `base` 字符串溢出

### 输出

- 直接修改 `base` 数组，将 `insert` 字符串插入到 `base` 字符串的 `pos` 位置后（即让 `insert[0]` 紧跟 `base[pos - 1]`）

## 样例

### 样例输入

按 `base - insert - pos` 顺序：

```
bilibili acfun 0
fuck uuuuuuuuu 2
```

### 样例输出

```
acfunbilibili
fuuuuuuuuuuck
```

### 考点

- 数组
- 循环

---

## 03 - 算多项式

给定 `x` ，`a0, a1, ... , an` ，试求以下多项式的值

$$
a_nx^n + a_{n-1}x^{n-1} + \cdots + a_2x^2 + a_1x + a_0
$$

### 输入

- `int` 类型的正整数 `n`
- `int` 类型的数字 `x`
- `int` 类型的数组 `a` ，`a[i]` 即代表多项式中的 $a_i$

### 输出

- `?` 类型的数字 `result` ，为防止数字过大，只需要返回多项式对 $10,000,000,007$ 取模的结果

### 样例

#### 样例输入

```
n=5 x=1000000012
a=[5, 4, 3, 0, 2, 1]
```

#### 样例输出

```
18511
```

---

## 04 - 屑推荐算法

最简单的推荐算法是根据广告客户给的钱的多少设定各个的广告出现的概率，简单来说，出的钱越多，广告出现的可能性就越大。现在已知 `n` 个广告客户付给平台的广告费用 `[a1,a2,...,an]` ，且第 `k` 个广告出现的概率为：

$$
P_k = \frac{a_k}{\sum_{i=1}^n a_i} = \frac{a_k}{a_1 + a_2 \cdots + a_n}
$$

请你从大到小排序广告出现的概率并打印对应的公司编号

### 输入

- 一个 `int` 类型的正整数 `1 < n < 100`
- 数组 `a[]` ，其中 `a[0], a[1] ... a[n-1]` 是 `n` 个广告商给的费用（保证各不相同）

### 输出

- 将 `n` 个广告的出现概率与序号（从 `1` 到 `n`）直接打印在屏幕上，格式为：

```
[编号（不满足两位数的在前方加 0）] [概率（百分数表示，保留两位小数）]
```

### 样例

#### 样例输入

```
n=12 a=[125, 100, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50]
```

#### 样例输出

```
01 25.00%
02 20.00%
03 10.00%
04 9.00%
05 8.00%
06 7.00%
07 6.00%
08 5.00%
09 4.00%
10 3.00%
11 2.00%
12 1.00%
```

### 考点

- 排序
- 格式化输出

---

## 05 - 初入递归（分解问题）

给定一个初始数字 `n` ，对它可以进行以下操作：

1. 什么都不做
2. 在它的左侧加上一个新的不大于原来最左侧数字的一半的自然数
3. 重复 2 操作数次，最多能重复到左侧无法再加数为止

现在给定数字 `n` ，求通过以上方法能生成多少个数

### 输入

- `int` 类型的数字 `1 < n < 1000`

### 输出

- 一个 `int` 类型的数字，`n` 按照上述方法能生成多少种不同的东西

### 样例

#### 样例输入

```
6
5
```

#### 样例输出

```
6
4
```

#### 样例说明

对于输入 `5` ，满足条件的生成物有：

```
5 1-5 2-5 1-2-5
```

对于输入 `6` ，满足条件的生成物有：

```
6 1-6 2-6 3-6 1-3-6 1-2-6
```

### 考点

- 递归

