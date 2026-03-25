#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
#define ll long long

vector<ll> tree, arr;

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    } 

    int mid = (l+r)/2;
    build(node*2, l, mid); build(node*2+1, mid+1, r);

    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[node];

    int mid = (l+r)/2;
    return query(node*2, l, mid, ql, qr) + query(node*2+1, mid+1, r, ql, qr);

}

void update(int node, int l, int r, int val, int pos) {
    if (pos < l || pos > r) return;
    if (l == r) {
        tree[node] = val;
        arr[l] = val;
        return;
    }

    int mid = (l+r)/2;
    update(node*2, l, mid, val, pos); update(node*2+1, mid+1, r, val, pos);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,q,a,b,x;
    cin >> n >> q;

    arr.resize(n, 0); tree.resize(n*4, 0); 
    for (auto &x : arr) cin >> x;

    build(1, 0, n-1);

    while (q--) {
        cin >> x >> a >> b;
        if (x == 2) cout << query(1, 0, n-1, a-1, b-1) << '\n';
        else update(1, 0, n-1, b, a-1);
    }
}