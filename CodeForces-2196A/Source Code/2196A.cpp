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
