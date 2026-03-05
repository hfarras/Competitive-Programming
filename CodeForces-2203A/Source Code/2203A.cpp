#include<bits/stdc++.h>
using namespace std;

int cont_tow(float n, float m, float d) {
    float stack = floor((d+m)/m);
    int tow = 0;
    while(n >= stack) { //divide while n is greater than stack 
        tow++;
        n -= stack;
    }
    if(n < stack && n > 0) tow++; // remainder of n
    return tow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        float n, m, d;
        cin >> n >> m >> d;
        cout << cont_tow(n, m, d) << "\n";
    }
}