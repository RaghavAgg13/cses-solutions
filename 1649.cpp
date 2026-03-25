#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
#define ll long long

int n,q,a,b,x,i;
vector<ll> arr, t;

void build(int root, int l, int r) {
    if (l == r) t[root] = arr[l];
    else {
        int mid  = l + (r-l)/2;
        build(root*2, l, mid);
        build(root*2+1, mid+1, r);

        t[root] = min(t[root*2],t[root*2+1]);
    }
}

void update(int root, int l, int r, int pos, int val) {
    if (l == r) t[root] = val;
    else {
        int mid = l + (r-l)/2;

        if (pos <= mid) update(root*2, l, mid, pos, val);
        else update(root*2+1, mid+1, r, pos, val);

        t[root] = min(t[root*2],t[root*2+1]); 
    }
}

ll query(int root, int l, int r, int a, int b) {
    if (a > b) return INT_MAX;
    if (l == a && r == b) return t[root];

    int mid = l + (r-l)/2;
    return min(query(root*2, l, mid, a, min(b, mid)), query(root*2+1, mid+1, r, max(a, mid+1), b));
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> q;
    
    arr.resize(n);
    t.resize(n*4);
    for (i = 0; i < n; i++) cin >> arr[i];

    build(1, 0, n-1);

    while (q--) {
        cin >> x >> a >> b;

        if (x == 1) update(1, 0, n-1, a-1, b);
        else cout << query(1, 0, n-1, a-1, b-1) << '\n'; 
    }
}   