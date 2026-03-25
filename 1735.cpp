#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<ll> tree, arr, lazy_set, lazy_add;

void pushDown(int node, int l, int r) {
    int mid = (l+r)/2;
    if (lazy_set[node]) {
        tree[node*2] = 1LL*(mid-l+1)*lazy_set[node];
        tree[node*2+1] = 1LL*(r-mid)*lazy_set[node];
        
        lazy_set[node*2] = lazy_set[node];
        lazy_set[node*2+1] = lazy_set[node];
        lazy_add[node*2] = lazy_add[node*2+1] = 0;
        lazy_set[node] = 0;
    }

    if (lazy_add[node]) {
        tree[node*2] += 1LL*(mid-l+1)*lazy_add[node];
        tree[node*2+1] += 1LL*(r-mid)*lazy_add[node];
        
        lazy_add[node*2] += lazy_add[node];
        lazy_add[node*2+1] += lazy_add[node];
        lazy_add[node] = 0;
    }
}

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
    if (qr < l || ql > r) return 0;
     if (ql <= l && r <= qr) return tree[node];
    
    pushDown(node, l, r);
    int mid = (l+r)/2;
    return query(node*2, l, mid, ql, qr) + query(node*2+1, mid+1, r, ql, qr);
}

void set(int node, int l, int r, int val, int ql, int qr) {
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr) {
        tree[node] = 1LL*val*(r-l+1);

        lazy_set[node] = val;
        lazy_add[node] = 0;
        return;
    }

    pushDown(node, l, r);
    int mid = (l+r)/2;
    set(node*2, l, mid, val, ql, qr); set(node*2+1, mid+1, r, val, ql, qr);

    tree[node] = tree[node*2] + tree[node*2+1];
}

void add(int node, int l, int r, int val, int ql, int qr) {
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr) {
        tree[node] += 1LL*val*(r-l+1);

        lazy_add[node] += val;
        return;
    }

    pushDown(node, l, r);
    int mid = (l+r)/2;
    add(node*2, l, mid, val, ql, qr); add(node*2+1, mid+1, r, val, ql, qr);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,q,x,a,b;
    cin >> n >> q;

    arr.resize(n, 0); tree.resize(n*4);
    lazy_add.resize(n*4); lazy_set.resize(n*4);
    for (auto &x : arr) cin >> x;

    build(1, 0, n-1);

    while (q--) {
        cin >> x >> a >> b;
        if (x == 1) {
            int tmp;
            cin >> tmp;
            add(1, 0, n-1, tmp, a-1, b-1);
        }
        else if (x == 2) {
            int tmp;
            cin >> tmp;
            set(1, 0, n-1, tmp, a-1, b-1);
        }
        else {
            cout << query(1, 0, n-1, a-1, b-1) << '\n';
        }
    }
}