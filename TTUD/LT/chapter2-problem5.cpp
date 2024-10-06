#include <bits/stdc++.h> 
using namespace std;
#define faster() ios_base::sync_with_stdio(0);

long long rmq[30][1000001];
int n;

int main() 
{ 
    faster();
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int k =ceil(log2(n));
    for (int i = 0; i < n; i++) {
        cin >> rmq[0][i];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 0; (1 << i) + j - 1 < n; j++) {
            rmq[i][j] = rmq[i - 1][j] < rmq[i - 1][j + (1 << (i - 1))] ? rmq[i - 1][j] : rmq[i - 1][j + (1 << (i - 1))];
        }
    }
    int m;
    cin >> m;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        k = floor(log2(y - x + 1));
        sum += min(rmq[k][x], rmq[k][y - (1 << k) + 1]);
    }
    cout << sum << endl;
    return 0;
}
