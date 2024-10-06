#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1] = {};
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++) {
            cin >> a[i][j];
        }
    }

    int result[n + 1][m + 1] = {};
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            result[i][j] = result[i][j - 1] + result[i - 1][j] - result[i - 1][j - 1] + a[i][j];
        }
    }

    // cout << endl;

    // for (int i = 0; i < n + 1; i++) {
    //     for (int j = 0; j < m + 1; j++) {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int k, c, d, e, f, s;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> c >> d >> e >> f;
        s = result[e][f] - result[e][d - 1] - result[c - 1][f] + result[c - 1][d - 1];
        cout << s << endl;
    }
    
    return 0;
}
