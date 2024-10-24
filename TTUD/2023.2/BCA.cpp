#include <bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0);

vector<vector<int>> teacher;
vector<vector<int>> courses;
vector<vector<int>> conflict;
vector<int> load;
int minLoad = INT_MAX;
int n, m;

void input() {
    cin >> n >> m;
    teacher.resize(n + 1);
    courses.resize(n + 1);
    load.resize(n + 1, 0);
    int k;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        courses[i].resize(k + 1);
        for (int j = 1; j <= k; ++j) {
            cin >> courses[i][j];
        }
    }
    conflict.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
        conflict[i].resize(m + 1);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        conflict[x][y] = 1;
        conflict[y][x] = 1;
    }
}

bool check(int i, int k) {
    if (find(courses[i].begin(), courses[i].end(), k) != courses[i].end()) {
        for (int j = 0; j < teacher[i].size(); ++j) {
            if (conflict[teacher[i][j]][k]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

void checkSolution() {
    int currLoad = load[0];
    for (int i = 1; i < n; ++i) {
        currLoad = max(currLoad, load[i]);
    }
    minLoad = min(currLoad, minLoad);
}

void TRY(int k) {
    for (int i = 1; i <= n; ++i) {
        if (check(i, k)) {
            teacher[i].push_back(k);
            load[i]++;
            if (k == m) checkSolution();
            if (load[i] < minLoad) {
                TRY(k + 1);
            }
            teacher[i].pop_back();
            load[i]--;
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    faster();
    input();
    TRY(1);
    cout << minLoad << endl;
    return 0;
}
