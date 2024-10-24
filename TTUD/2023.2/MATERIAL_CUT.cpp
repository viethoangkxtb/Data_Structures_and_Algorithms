#include <bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0);

int h, w;
int n;
int sub[11][2];

bool canCut(int usedH, int usedW, int i) {
    if (i > n) {
        return (usedH == h && usedW == w);
    }
    //Cắt chiều cao của hình chính bằng chiều cao của hình con
    if (sub[i][0] <= h - usedH) {
        if (canCut(usedH + sub[i][0], usedW, i + 1)) {
            return true;
        }
    }
    //Cắt chiều cao của hình chính bằng chiều rộng của hình con
    if (sub[i][1] <= h - usedH) {
        if (canCut(usedH + sub[i][1], usedW, i + 1)) {
            return true;
        }
    }
    //Cắt chiều rộng của hình chính bằng chiều cao của hình con
    if (sub[i][0] <= w - usedW) {
        if (canCut(usedH, usedW + sub[i][0], i + 1)) {
            return true;
        }
    }
    //Cắt chiều rộng của hình chính bằng chiều rộng của hình con
    if (sub[i][1] <= w - usedW) {
        if (canCut(usedH, usedW + sub[i][1], i + 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    faster();
    cin >> h >> w;
    cin >> n;
    for (int i = 1; i < n + 1; i++) {
        cin >> sub[i][0] >> sub[i][1];
    }
    cout << (canCut(0, 0, 1) ? 1 : 0) << endl;
    return 0;
}
