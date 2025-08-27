#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        if (n == 2) {
            if (s[0] == s[1]) return s;
            return s.substr(0,1);
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        int start = 0, maxLen = 1;

        // độ dài = 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = 1;
                start = i;
                maxLen = 2;
            }
        }

        // độ dài >= 3
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = 1;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Nhap chuoi: ";
    cin >> s;
    cout << "Chuoi doi xung dai nhat: " << sol.longestPalindrome(s) << endl;
    return 0;
}
