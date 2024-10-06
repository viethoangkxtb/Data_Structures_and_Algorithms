#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, Q;
    cin >> n >> Q;

    int a[n + 1] = {};
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }

    int count = 0;
    int L = 1, R = 1;
    int S = 0;
    
    for (R = 1; R < n + 1; R++) {
        S += a[R];
        while (S > Q) {
            S = S - a[L];
            L++;
        }
        count = max (count, R - L + 1);
    }

    if (count == 0) {
        cout << -1;
    } else {
        cout << count;
    }
    
    return 0;
}