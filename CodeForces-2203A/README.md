# 2203A - Tower of Boxes

Source : (https://codeforces.com/contest/2203/problem/A)

Monocarp has ***n*** identical boxes. The weight of each box is ***m***, and the durability of each box is ***d***.

To save space, Monocarp wants to build several "towers" of boxes by stacking them on top of each other. Each tower will consist of a positive (greater than 0) integer number of boxes stacked on top of each other. To ensure that no box breaks, the following condition must be met:

- for each box, the **total** weight of all boxes above it must not exceed the durability of that box.

Help Monocarp calculate the minimum number of towers he can achieve, given that each of the nboxes must be used.

### Input

The first line contains a single integer ***t (1 ≤ t ≤ 10<sup>4</sup>)*** — the number of test cases.

Each test case consists of a single line containing three integers ***n, m, d (1 ≤ n, m, d ≤ 50)***.

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

In the first example, it is possible to build three towers consisting of **3**, **2**, and **3** boxes, respectively.

In the second example, all boxes are durable enough to build one tower of **8** boxes.

In the third example, the weight of the box exceeds its durability, so they cannot be stacked on top of each other. As a result, **5** separate towers will have to be built.

## Solve Documentation
Given that:
-  Monocarp has ***n*** identical boxes
-  The weight of each box is ***m***
-  The durability of each box is ***d***

Monocarp wants to build several towers by stacking boxes on top of each other and must contain at least one box. 

#### Constraint 

For **every box**, the **total weight of all boxes above it must not exceed its durability**.

Because all boxes are idenctical, each box weighs ***m***, and box durability ***d***.

$$ m + d <= d $$

So, there are **k** boxes in each stack

$$ k = \left\lfloor \frac{d+m}{m} \right\rfloor$$

### Example Analysis

$$ n = 8, m = 10, d = 20 $$

***k*** boxes in each stack:

$$ k = \left\lfloor \frac{30}{10} \right\rfloor$$
$$ k = \left\lfloor 3 \right\rfloor$$
$$ k = 3$$

If **k ≤ n**, then **n - k**.
If **k > n**, then **n**

$$ 8 -> 3 + 5 -> 3 + 3 + 2 $$

Therefore are 3 stack with each stack has 3 boxes, 3 boxes, and 2 boxes;

### Code Implementation
```c++
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--) {
        float n, m, d;
        cin >> n >> m >> d;
 
        float stack = floor((d+m)/m);
        int tow = 0;
        
        while(n >= stack) {
            tow++;
            n = n - stack;
        }
        if(n < stack && n > 0) tow++; //remainder n > 0 & n < divider
        cout << tow << "\n";
    }
}

```
   
