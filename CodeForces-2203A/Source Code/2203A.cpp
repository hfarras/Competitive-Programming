#include<bits/stdc++.h>
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m, d;
        scanf("%d %d %d", &n, &m, &d);
 
        int k = (d / m) + 1;          // maximum boxes per tower
        int towers = (n + k - 1) / k; // ceil(n / k)
        printf("%d\n", towers);
    }
}
