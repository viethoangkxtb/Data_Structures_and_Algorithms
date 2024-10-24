#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Treasure {
    int x, y, c;
};

bool compareTreasure(const Treasure& a, const Treasure& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main() {
    int n;
    cin >> n;
    vector<Treasure> treasures(n);

    for (int i = 0; i < n; ++i) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].c;
    }

    // Sort treasures based on their x and y coordinates
    sort(treasures.begin(), treasures.end(), compareTreasure);

    // Compress y coordinates
    map<int, int> compress;
    for (const auto& treasure : treasures) {
        compress[treasure.y] = 0;
    }

    int index = 0;
    for (auto& entry : compress) {
        entry.second = index++;
    }

    vector<long long> dp(index, 0);

    long long maxGold = 0;

    for (const auto& treasure : treasures) {
        int yIndex = compress[treasure.y];
        long long currentMaxGold = 0;

        for (int i = 0; i <= yIndex; ++i) {
            currentMaxGold = max(currentMaxGold, dp[i]);
        }

        dp[yIndex] = max(dp[yIndex], currentMaxGold + treasure.c);
        maxGold = max(maxGold, dp[yIndex]);
    }

    cout << maxGold << endl;

    return 0;
}
