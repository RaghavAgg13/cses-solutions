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

    tree[node] = min(tree[node*2], tree[node*2+1]);
}

ll query(int node, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return INT_MAX;
    if (ql <= l && r <= qr) return tree[node];

    int mid = (l+r)/2;
    return min(query(node*2, l, mid, ql, qr), query(node*2+1, mid+1, r, ql, qr));

}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,q,a,b;
    cin >> n >> q;

    arr.resize(n, 0); tree.resize(n*4, 0); 
    for (auto &x : arr) cin >> x;

    build(1, 0, n-1);

    while (q--) {
        cin >> a >> b;
        cout << query(1, 0, n-1, a-1, b-1) << '\n';
    }
}