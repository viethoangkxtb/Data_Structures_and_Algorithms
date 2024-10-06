// Cách 2
#include<bits/stdc++.h>
using namespace std;

int result (int arr[], int n) {
    stack <int> left;
    stack <int> right;

    int l[n] = {};
    int r[n] = {};
    
    left.push(0);
    
    int temp = left.top();

    for (int i = 1; i < n; i++) {
        temp = left.top();
        if (arr[i] > arr[temp]) {
            left.push(i);
            l[i] = i;
        }
        else {
            while (!left.empty()) {
                if (arr[i] <= arr[left.top()]) {
                    temp = left.top();
                    left.pop();
                }
                else {
                    l[i] = l[temp];
                    break;
                }
            }
            left.push(i);
        }
    }
    r[n - 1] = n - 1;
    right.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        r[i] = n - 1;
        temp = right.top();
        if (arr[i] > arr[temp]) {
            right.push(i);
            r[i] = i;
        }
        else {
            while (!right.empty()) {
                if (arr[i] <= arr[right.top()]) {
                    temp = right.top();
                    right.pop();
                }
                else {
                    r[i] = r[temp];
                    break;
                }
            }
            right.push(i);
        }
    }

    int max = 0;
    int check = 0;

    for (int i = 0; i < n; i++) {
        check = (r[i] - l[i] + 1) * arr[i];
        if (check > max) {
            max = check;
        }
    }
    
    return max;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int arr[m] = {};
    int count[n] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                arr[j] = 0;
            } else {
                arr[j]++;
            }
        }
        count[i] = result (arr, m);
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (max < count[i]) {
            max = count[i];
        }
    }
    cout << max;

    return 0;
}


// Cách 1

// #include<bits/stdc++.h>
// using namespace std;
// int n, m;
// int a[1001][1001] = {};
// int b[1001][1001] = {};

// void input() {
//     cin >> n >> m;
//     for (int i = 1; i < n + 1; i++) {
//         for (int j = 1; j < m + 1; j++) {
//             cin >> a[i][j];
//         }
//     }
// }

// void preProcessData() {
//     for (int i = 1; i < n + 1; i++) {
//         for (int j = 1; j < m + 1; j++) {
//             if (a[i][j] == 0) {
//                 continue;
//             } else {
//                 b[i][j] = b[i - 1][j] + 1;
//             }
//         }
//     }
// }

// int loopPerRow(int x) {
//     int L[m + 1] = {};
//     int R[m + 1] = {};

//     if (b[x][1] == 0) {
//         L[1] = 0;
//     } else {
//         L[1] = 1;
//     }

//     // for (int i = 1; i < m + 1; i++) {
//     //     cout << b[x][i] << " ";
//     // }

//     // cout << endl;

//     for (int i = 2; i < m + 1; i++) {
//         if (b[x][i] == 0) {
//             L[i] = 0;
//         } else {
//             if (b[x][i - 1] < b[x][i]) {
//                 L[i] = 1;
//             } else if (b[x][i - 1] == b[x][i]) {
//                 L[i] = L[i - 1] + 1;
//             } else {
//                 L[i] = 1;
//                 for (int j = i - 1; j > 0; j--) {
//                     if (b[x][j] >= b[x][i]) {
//                         L[i]++;
//                     } else {
//                         break;
//                     }
//                 }
//             }
//         }
//     }

//     if (b[x][m] == 0) {
//         R[m] = 0;
//     } else {
//         R[m] = 1;
//     }
    
//     for (int i = m - 1; i > 0; i--) {
//         if (b[x][i] == 0) {
//             R[i] = 0;
//         } else if (b[x][i] > b[x][i + 1]) {
//             R[i] = 1;
//         } else if (b[x][i] == b[x][i + 1]){
//             R[i] = R[i + 1] + 1;
//         } else {
//             R[i] = 1;
//             for (int j = i + 1; j < m + 1; j++) {
//                 if (b[x][i] <= b[x][j]) {
//                     R[i]++;
//                 } else {
//                     break;
//                 }
//             }
//         }
//     }

//     // cout << "Highest of 1left " << x << ": ";
//     // for (int i = 1; i < m + 1; i++) {
//     //     cout << L[i] << " ";
//     // }
//     // cout << endl;

//     // cout << "Highest of right " << x << ": ";
//     // for (int i = 1; i < m + 1; i++) {
//     //     cout << R[i] << " ";
//     // }
//     // cout << endl << endl;

//     int maxS = 0;
//     int tmp;
//     for (int i = 1; i < m + 1; i++) {
//         tmp = b[x][i] * (R[i] + L[i] - 1);
//         maxS = max(maxS, tmp);
//     }

//     return maxS;
// }

// int main() {
//     input();
//     preProcessData();

//     // for (int i = 1; i < n + 1; i++) {
//     //     for (int j = 1; j < m + 1; j++) {
//     //         cout << a[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     // for (int i = 1; i < n + 1; i++) {
//     //     for (int j = 1; j < m + 1; j++) {
//     //         cout << b[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     int maxS = 0;
//     for (int i = 1; i < n + 1; i++) {
//         maxS = max(maxS, loopPerRow(i));
//     }

//     cout << maxS;


//     return 0;
// }