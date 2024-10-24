/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

bool sortDisjointSegment (const pair<int, int> a, const pair<int, int> b) {
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair <int, int>> a;
    pair<int, int> b;
    for (int i = 0; i < n; i++) {
        cin >> b.first >> b.second;
        a.push_back(b);
    }
    
    sort (a.begin(), a.end(), sortDisjointSegment);
    
    int result = 1;
    int next = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i].first > a[next].second) {
            next = i;
            result++;
        }
    }
    
    cout << result;

    return 0;
}
