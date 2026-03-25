#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
#define ll long long

int n,q,x,i;
vector<ll> arr, t;

void build(int root, int l, int r) {
    if (l == r) t[root] = arr[l];
    else {
        int mid  = l + (r-l)/2;
        build(root*2, l, mid);
        build(root*2+1, mid+1, r);

        t[root] = max(t[root*2],t[root*2+1]);
    }
}

int query(int root, int l, int r, int val) {
    if (t[root] < val) return 0;
    if (l == r) {
        t[root] -= val;
        return l+1;
    }

    int mid = l + (r-l)/2;
    int idx;

    if (t[root*2] >= val) idx = query(root*2, l, mid, val);
    else idx = query(root*2+1, mid+1, r, val);

    t[root] = max(t[root*2], t[root*2+1]);
    return idx;
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
        cin >> x;

        cout << query(1, 0, n-1, x) << ' ';
    }
}   