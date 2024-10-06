#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void build(vector<int>& a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
        } else {
            int mid = (start + end) / 2;
            build(a, 2 * node + 1, start, mid);
            build(a, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int getMax(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return INT_MIN;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftMax = getMax(2 * node + 1, start, mid, l, r);
        int rightMax = getMax(2 * node + 2, mid + 1, end, l, r);
        return max(leftMax, rightMax);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree segTree(n);
    segTree.build(a, 0, 0, n - 1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string action;
        cin >> action;
        if (action == "get-max") {
            int l, r;
            cin >> l >> r;
            cout << segTree.getMax(0, 0, n - 1, l - 1, r - 1) << endl;
        } else if (action == "update") {
            int idx, value;
            cin >> idx >> value;
            segTree.update(0, 0, n - 1, idx - 1, value);
        }
    }

    return 0;
}
