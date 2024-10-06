#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    
    int a[n + 1] = {};
    for (int i = 1 ; i < n + 1; i++) {
        cin >> a[i];
    }

    // Sort the array
    sort(a + 1, a + n + 1);
// for (int i = 1 ; i < n + 1; i++) {
//         cout << a[i];
//     }
//     cout << endl;
    int res = 0;
    int i = 1, j = n;
    while (i < j) 
    {
        if (a[i] + a[j] == M) {
            res = res + 1; 
            i = i + 1; 
            j = j - 1;
        } else if (a[i] + a[j] < M) {
            i = i + 1;
        }
        else {
            j = j - 1; 
        }
            
    }
    cout << res;
    return 0;
}