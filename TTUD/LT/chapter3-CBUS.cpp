#include <bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0);

int n, k;
int c[2001][2001] = {};
int cmin = INT_MAX;
int minRoute = INT_MAX;
bool appear[2001] = {};

bool check(int x, int places) {
    if (appear[x]) return false;
    if (x <= n) {
        if (places >= k) return false;
    } else {
        if (!appear[x - n]) return false;
    }
    return true;
}

void TRY(int i, int preVisit, int places = 0, int totalDist = 0) {
    if (totalDist + cmin * (2 * n - i + 1) >= minRoute) return;

    if (i == 2 * n) {
        totalDist += c[preVisit][0];
        minRoute = min(minRoute, totalDist);
        return;
    }

    for (int x = 1; x < 2 * n + 1; ++x) {
        if (check(x, places)) {
            totalDist += c[preVisit][x];
            appear[x] = true;
            if (x <= n) {
                TRY(i + 1, x, places + 1, totalDist);
            } else {
                TRY(i + 1, x, places - 1, totalDist);
            }
            totalDist -= c[preVisit][x];
            appear[x] = false;
        }
    }
}

int main() {
    faster();
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < (2 * n + 1); ++i) {
        for (int j = 0; j < (2 * n + 1); ++j) {
            cin >> c[i][j];
            if (c[i][j]) cmin = c[i][j] < cmin ? c[i][j] : cmin;
        }
    }

    TRY(0, 0);
    cout << minRoute << endl;
    return 0;
}
