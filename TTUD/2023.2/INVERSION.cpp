#include <bits/stdc++.h>
using namespace std;

#define MAX 1000006
int const MOD = 1e9+7;
int n, a[MAX];
int temp[MAX];

int merge(int left, int mid, int right) {
    int i = left, j = mid+1, k = left, count = 0;
    while((i <= mid) && (j <= right)) {
        if(a[i] <= a[j])
            temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            count = (count + (mid -i +1)) % MOD;
        }
    }
    while(i <= mid) 
        temp[k++] = a[i++];
    while(j <= right)
        temp[k++] = a[j++];
    for(i = left; i <= right; i++)
        a[i] = temp[i];
    
    return count;
}

int mergeSort(int left, int right) {
    int mid; 
    int count = 0;
    if(right > left) {
        mid = (right + left) /2;
    count = (count + mergeSort(left, mid)) % MOD;
    count = (count + mergeSort(mid + 1, right)) % MOD;
    count = (count + merge(left, mid, right))% MOD;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++)     
        cin >> a[i];
    cout << mergeSort(1,n);
    
    return 0;
}
