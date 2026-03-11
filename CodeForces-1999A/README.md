# 1999A - A+B Again?

Source : (https://codeforces.com/problemset/problem/1999/A)

Given a two-digit positive integer `n`, find the sum of its digits.

### Input

The first line contains an integer `t` $`(1 \le t \le 90)`$ — the number of test cases.

The only line of each test case contains a single two-digit positive integer `n` $`(10 \le n \le99)`$.

### Output

For each test case, output a single integer — the sum of the digits of `n`.

### Example
#### input

```c++
8
77
21
40
34
19
84
10
99
```

#### output

```c++
14
3
4
7
10
12
1
18
```
## Solve Documentation

### Problem Understanding

We are given a **two-digit positive integer** `n` for each test case, and our task is to compute the **sum of its digits**.

Since `n` is guaranteed to be between **10 and 99**, we can represent it as:

$$ n = \overline{ab} $$

Where:

- `a` = tens digit  
- `b` = units digit  

For example:

| n | a | b |
|---|---|---|
| 77 | 7 | 7 |
| 21 | 2 | 1 |
| 40 | 4 | 0 |

Our goal is simply:

$$ \text{sum} = a + b $$

---

### Approach

To extract each digit efficiently, we can use **basic arithmetic operations**.

#### Extract the Units Digit

The **last digit** of a number can be obtained using the modulo operator.

$$ b = n \bmod 10 $$

Example:

$$ 77 \bmod 10 = 7 $$

---

#### Extract the Tens Digit

If we subtract the units digit from `n`, we obtain a number that always ends with `0`.

$$ n - b = \overline{a0} $$

Dividing by `10` gives the tens digit:

$$ a = \frac{n - b}{10} $$

Example:

$$ a = \frac{77 - 7}{10} = \frac{70}{10} = 7 $$

---

#### Compute the Sum

Finally, we add both digits:


$$ \text{sum} = a + b $$

---

### Example Walkthrough

#### Example 1

Input

```text
n = 77
```

Extract digits

$$ b = 77 \bmod 10 = 7 $$

$$ a = \frac{77 - 7}{10} = 7 $$

Compute the sum

$$ 7 + 7 = 14 $$

Output

```text
14
```

---

#### Example 2

Input

```text
n = 21
```

Extract digits

$$ b = 21 \bmod 10 = 1 $$

$$ a = \frac{21 - 1}{10} = 2 $$

Compute the sum

$$ 2 + 1 = 3 $$

Output

```text
3
```

---

### Complexity Analysis

For each test case, we perform only a few **constant-time arithmetic operations**:

- modulo
- subtraction
- division
- addition

Therefore:

#### Time Complexity

$$ O(t) $$

Where:

- `t` = number of test cases  
- $`(1 \le t \le 90)`$

This solution is extremely efficient and easily satisfies the problem constraints.

---

### Code Implementation

```cpp
#include <bits/stdc++.h>
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int ab;
        scanf("%d", &ab);

        int a = ab % 10;
        int b = (ab - a) / 10;
        printf("%d\n", a + b );
    }
}
```

---

### Key Insight

Since the input number always contains **exactly two digits**, we can extract each digit using simple arithmetic operations (`%` and `/`) without needing loops or string manipulation. This keeps the solution **clean, simple, and efficient**.
