#include <bits/stdc++.h>
using namespace std;

int n;

int result = 0;

void TRY(int k, int m, int a[]) {
    for (int i = 1; i <= m/a[k]; i++) {
        if (k == n) {
            if (m == i * a[k]) {
                result++;
            }
        }
        else {
            TRY(k + 1, m - i * a[k], a);
        }
    }
}

int main() {
    int m;
    cin >> n >> m;
    int a[n + 1] = {};
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }
    
    TRY (1, m, a);
    cout << result;
    
    return 0;
}
