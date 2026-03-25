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

    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int firstAtLeast(int node, int l, int r, int threshold) {
    if (tree[node] < threshold) return 0;
    if (l == r) {
        tree[node] -= threshold;
        return l+1;
    }

    int mid = (l+r)/2, idx;
    if (tree[node*2] >= threshold) idx = firstAtLeast(node*2, l, mid, threshold);
    else idx = firstAtLeast(node*2+1, mid+1, r, threshold);
    
    tree[node] = max(tree[node*2], tree[node*2+1]);

    return idx;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,q,x;
    cin >> n >> q;

    arr.resize(n, 0); tree.resize(n*4, 0); 
    for (auto &x : arr) cin >> x;

    build(1, 0, n-1);

    while (q--) {
        cin >> x;
        cout << firstAtLeast(1, 0, n-1, x) << ' ';
    }
}