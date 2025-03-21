// 나중에 다시 풀기

#include <iostream>
#include <vector>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct SegmentTree {
    vector<int> tree;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n);
    }

    void build(const vector<int>& arr, int node, int start, int end, bool even) {
        if (start == end) {
            tree[node] = (arr[start] % 2 == (even ? 0 : 1)) ? 1 : 0;
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid, even);
            build(arr, 2 * node + 1, mid + 1, end, even);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, int val, bool even) {
        if (start == end) {
            tree[node] = (val % 2 == (even ? 0 : 1)) ? 1 : 0;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, val, even);
            else
                update(2 * node + 1, mid + 1, end, idx, val, even);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r)
             + query(2 * node + 1, mid + 1, end, l, r);
    }
};

int main() {
    FastIO
    int N;
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];

    SegmentTree evenTree(N), oddTree(N);
    evenTree.build(arr, 1, 1, N, true);
    oddTree.build(arr, 1, 1, N, false);

    int Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            if ((arr[i] % 2) != (x % 2)) {
                evenTree.update(1, 1, N, i, x, true);
                oddTree.update(1, 1, N, i, x, false);
            }
            arr[i] = x;
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << evenTree.query(1, 1, N, l, r) << '\n';
        } else if (type == 3) {
            int l, r;
            cin >> l >> r;
            cout << oddTree.query(1, 1, N, l, r) << '\n';
        }
    }
    return 0;
}
