#include <iostream>
#include <vector>
using namespace std;

vector<int> tree, arr, nos;

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = arr[l];
        return;
    } 

    int mid = (l+r)/2;
    build(node*2, l, mid); build(node*2+1, mid+1, r);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int walk(int node, int l, int r, int pos) {
    if (l == r) {
        tree[node]--;    
        return l;
    }

    int mid = (l+r)/2, idx;
    if (tree[node*2] >= pos) idx = walk(node*2, l, mid, pos);
    else idx = walk(node*2+1, mid+1, r, pos-tree[node*2]);

    tree[node] = tree[node*2] + tree[node*2+1];
    return idx;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,i,x;
    cin >> n;

    arr.resize(n, 1); tree.resize(n*4); nos.resize(n);
    for (auto &x : nos) cin >> x;

    build(1, 0, n-1);

    for (i = 0; i < n; i++) {
        cin >> x;
        cout << nos[walk(1, 0, n-1, x)] << ' ';
    }
}