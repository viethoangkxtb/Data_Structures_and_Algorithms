#include <bits/stdc++.h>
using namespace std;

const int abc = 1e9 + 7;
long long s[10000] = {};

int main() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    
    s[0] = 1;
    s[1] = 1;
    
    for (int i = k1; i <= n + 1; i++) {
        for (int j = max(0, i - k2 - 1); j < i -k1; j++) {
            s[i] += (s[j] % abc);
        }
    }
    
    cout << s[n] + s[n + 1] << endl;
    
    return 0;
}
