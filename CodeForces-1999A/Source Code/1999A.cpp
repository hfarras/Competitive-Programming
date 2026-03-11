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