# 2203A - Tower of Boxes

Source : (https://codeforces.com/contest/2203/problem/A)

Monocarp has `n` identical boxes. The weight of each box is `m`, and the durability of each box is `d`.

To save space, Monocarp wants to build several "towers" of boxes by stacking them on top of each other. Each tower will consist of a positive (greater than 0) integer number of boxes stacked on top of each other. To ensure that no box breaks, the following condition must be met:

- for each box, the `total` weight of all boxes above it must not exceed the durability of that box.

Help Monocarp calculate the minimum number of towers he can achieve, given that each of the nboxes must be used.

### Input

The first line contains a single integer `t` $`(1 \le t \le 10^4)`$ — the number of test cases.

Each test case consists of a single line containing three integers  `n`, `m`, `d` $`(1 \le n, m, d \le 50)`$.

### Output

For each test case, print one integer — the minimum number of towers.

#### input

```c++
3
8 10 20
8 1 20
5 3 2
```

#### output

```c++
3
1
5
```

### Note

In the first example, it is possible to build three towers consisting of `3`, `2`, and `3` boxes, respectively.

In the second example, all boxes are durable enough to build one tower of `8` boxes.

In the third example, the weight of the box exceeds its durability, so they cannot be stacked on top of each other. As a result, `5` separate towers will have to be built.

## Solve Documentation

### Problem Understanding

We are given:

- `n` — the number of identical boxes  
- `m` — the weight of each box  
- `d` — the durability of each box  

Monocarp wants to stack these boxes into several **towers**. Each tower must contain **at least one box**.

However, there is a constraint:

> For every box, the **total weight of all boxes above it must not exceed its durability**.

Since all boxes are identical:

- Each box weighs `n`
- If a tower has `k` **boxes**, the bottom box must support the weight of the `k-1` boxes above it.

Therefore, the total weight above the bottom box is:

$$(k - 1) \times m $$

To prevent the box from breaking:

$$(k - 1) \times m \le d $$

---

### Maximum Boxes per Tower

From the constraint:

$$ (k - 1)m \le d $$

$$ k - 1 \le \frac{d}{m} $$

$$ k \le \frac{d}{m} + 1 $$

Thus, the **maximum number of boxes in a single tower** is:

$$ k = \left\lfloor \frac{d}{m} \right\rfloor + 1 $$

Which is equivalent to:

$$ k = \left\lfloor \frac{d + m}{m} \right\rfloor $$

This value represents the **maximum safe height** of a tower.

---

### Strategy

To **minimize the number of towers**, we should make each tower as tall as possible.

Steps:

1. Compute the maximum boxes per tower:

$$ k = \left\lfloor \frac{d + m}{m} \right\rfloor $$

2. Distribute all **n** boxes into towers of height **k**.

3. The minimum number of towers is:

$$ \text{towers} = \left\lceil \frac{n}{k} \right\rceil $$

---

### Example Walkthrough

#### Example 1

$$ n = 8, m = 10, d = 20 $$

Maximum boxes per tower:

$$ k = \left\lfloor \frac{20 + 10}{10} \right\rfloor = 3 $$

Each tower can contain at most `3` **boxes**.

Distribution:

$$ 8 = 3 + 3 + 2 $$

So the minimum number of towers is

$$ 3 $$

---

#### Example 2

$$ n = 8, m = 1, d = 20 $$

$$ k = \left\lfloor \frac{21}{1} \right\rfloor = 21 $$

Since **k > n**, all boxes can be placed in a **single tower**. Therefore the answer is

$$ 1 $$

---

#### Example 3

$$ n = 5, m = 3, d = 2 $$

$$ k = \left\lfloor \frac{5}{3} \right\rfloor = 1 $$

Only **one box per tower** is safe.

$$ 5 = 1 + 1 + 1 + 1 + 1 $$

Number of towers:

$$ 5 $$

---

### Complexity Analysis

For each test case, we only perform **simple arithmetic operations**.

Time Complexity:

$$  O(t) $$

Where:

- $` t \le 10^4 `$

This is efficient and easily fits within the problem constraints.

---

### Code Implementation

```cpp
#include<bits/stdc++.h>
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m, d;
        scanf("%d %d %d", &n, &m, &d);
 
        int k = (d / m) + 1;
        int towers = (n + k - 1) / k;
        printf("%d\n", towers);
    }
}
```
#### Key Insight
Since all boxes are identical, we only need to determine the **maximum safe height of a tower**. After that, the problem reduces to distributing `n` boxes into towers of size `k` to minimize the total number of towers.
