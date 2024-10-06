#include <bits/stdc++.h>
using namespace std;


int main() 
{ 
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q[n + 1] = {};
    q[1] = a[0];
    for (int i = 2; i < n + 1; i++) {
        q[i] = q[i - 1] + a[i - 1];
    }
    
    int m, f, b;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> f >> b;
        cout << q[b] - q[f - 1] << endl;
    }
}
