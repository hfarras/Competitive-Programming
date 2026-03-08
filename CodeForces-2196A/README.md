# 2196A - Game with a Fraction

Source : (https://codeforces.com/problemset/problem/2196/A)

Alice and Bob have two integers `p` and `q`, and they are playing a game with these numbers. The players take turns, with Alice going first. On their turn, a player can do one of two actions:

- decrease `p` by one (this action is possible if `p > 0`).
- decrease `q` by one (this action is possible if `q > 1`).

The game ends when `p = 0` and `q = 1`.

Bob wins if at any point during the game the fraction $` \frac{p}{q} `$ is equal to **in value** the fraction $`\frac{2}{3}`$. Otherwise, Alice wins.

Given the initial values of `p` and `q`, determine the winner of the game if both players play optimally.

### Input

Each test contains multiple test cases. The first line contains the number of test cases `t` **(1 ≤ t ≤ 10<sup>4</sup>)**. The description of the test cases follows.

Each input case consists of a single line containing two integers `p` and `q` **(1 ≤ p, q ≤ 10<sup>18</sup>)**.

### Output

For each input case, output:
- `"Alice"` if Alice wins.
- `"Bob"` if Bob wins.

#### input

```c++
6
4 6
10 14
15 15
7 12
7000000000000000 10487275715782582
1000000000000000000 1000000000000000000
```

#### output

```c++
Bob
Bob
Alice
Alice
Bob
Alice
```

### Note

In the first input case, the fraction is already equal to $`\frac{2}{3}`$ by value, so Bob wins.

In the second input case, one possible sequence of the game is as follows:
- initially `p = 10`, `q = 14`.
- after Alice's turn `p = 9`, `q = 14`.
- after Bob's turn `p = 9`, `q = 13`.
- after Alice's turn `p = 9`, `q = 12`.
- after Bob's turn `p = 8`, `q = 12`.

Bob wins, as $`\frac{8}{12}`$ is equal to $`\frac{2}{3}`$. It can be shown that in this example, with optimal play from both players, Bob always wins.

For the third input case, Alice's optimal strategy will be to decrease `q` as long as possible. In this case, the game will end in favor of Alice regardless of Bob's actions.

## Solve Documentation

### Problem Understanding

Alice and Bob are playing a game with two integers:

- `p`
- `q`

Rules of the game:

- Alice moves **first**.
- On each turn, a player can perform **one of two actions**:
  - Decrease `p` by `1` (if `p > 0`)
  - Decrease `q` by `1` (if `q > 1`)
 
The game **ends** when:

$$ p = 0 \ and \ q = 1 $$

However, there is a special winning condition:

> If at any moment the fraction **$`\frac{p}{q} = \frac{2}{3}`$**, Bob wins immediately.

Otherwise, if the game finishes without ever reaching that fraction, **Alice wins**.

Both players play **optimally**, and we must determine the winner.

---

### Key Observation

Bob wins when:

$$ \frac{p}{q} = \frac{2}{3} $$

This is equivalent to:

$$ 3p = 2q $$

During the game, players only **decrease** `p` or `q`. Therefore, the pair `(p, q)` moves only **downward** on the coordinate grid.

To analyze how far the current state is from the critical ratio, define:

$$ n = 3p − 2q $$


This value indicates the **distance from the line `3p = 2q`**.

---

### Case Analysis

#### Case 1 — Fraction already equals $`\frac{2}{3}`$

If:

$$ 3p = 2q $$


Then Bob wins **immediately**.

---

#### Case 2 — The value is already below the boundary

If:

$$ 3p − 2q < 0 $$

This means:

$$ \frac{p}{q} < \frac{2}{3} $$

Since both numbers can only decrease, the ratio will **never become $`\frac{2}{3}`$**.

Therefore:

```
Alice wins
```

---

#### Case 3 — Impossible to reach the boundary

Let:

$$ n = 3p − 2q $$

If:

$$ p < n \ and \ q < n $$

Then neither player can reduce the numbers in such a way to reach the equality:

$$ 3p = 2q $$

Thus:

```
Alice wins
```

---

#### Case 4 — Otherwise

If none of the above conditions occur, Bob can force the game to reach the ratio $`\frac{2}{3}`$.

Therefore:

```
Bob wins
```

---

### Example Walkthrough

#### Example 1

$$ p = 4, q = 6 $$

$$ \frac{p}{q} = \frac{4}{6} = \frac{2}{3} $$

The fraction is already equal to $`\frac{2}{3}`$.

Result:

```
Bob
```

---

#### Example 2

$$ p = 10, q = 14 $$

Possible sequence:

$$ (10,14) \ (9,14) \ (9,13) \ (9,12) \ (8,12) $$

Now:

$$ \frac{8}{12} = \frac{2}{3} $$

Bob wins.

---

#### Example 3

$$ p = 15, q = 15 $$


Alice can continuously decrease `q` to prevent reaching the ratio $`\frac{2}{3}`$`.

Result:

```
Alice
```

---

### Complexity Analysis

For each test case we only compute a few arithmetic operations.

Time Complexity:

$$ O(t) $$

Where:

```
t ≤ 10^4
```

Memory Complexity:

$$ O(1) $$

This works efficiently even when:

```
p, q ≤ 10^18
```

---

### Code Implementation
```cpp
#include <bits/stdc++.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long p, q;
        scanf("%lld %lld", &p , &q);

        long long n = 3*p - 2*q;
        if(n < 0 || p == q || (p < n && q < n)) {
            printf("%s\n", "Alice");
            continue;
        }
        else {
            printf("%s\n", "Bob");
        }
    }   
}
```

---

### Key Insight

Instead of simulating every move of the game, we analyze the **mathematical relationship between `p` and `q`**.

The critical condition is whether the game can reach:

$$ \frac{p}{q} = \frac{2}{3} $$

By transforming this into the equation:

$$ 3p = 2q $$

we can determine the winner in **constant time** per test case.
