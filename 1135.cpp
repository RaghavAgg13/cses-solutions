#include <iostream>
#include <vector>
using namespace std;

int n,q,a,b,tour_idx,i,j;
vector<int> nodes, depths, last, logs;
vector<vector<int>> adj, st; 

void tour(int root, int parent, int d) {
    nodes[tour_idx] = root;
    depths[tour_idx] = d;
    last[root] = tour_idx++;

    for (auto x : adj[root]) {
        if (x != parent) {
            tour(x, root, d+1);
            nodes[tour_idx] = root;
            depths[tour_idx] = d;
            last[root] = tour_idx++;
        }
    }
} 

void buildSparseTable(int root) {
    int len = n*2-1;
    logs.resize(len+1, 0);
    logs[1] = 0;

    for (i = 2; i <= len; i++) logs[i] = logs[i/2]+1;

    st.resize(len, vector<int>(logs[len]+1, 0));
    for (i = 0; i < len; i++) st[i][0] = i;

    for (j = 1; (1 << j) <= len; j++) {
        for (i = 0; i + (1 << j)-1 < len; i++) {
            int l = st[i][j - 1], r = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = depths[l] < depths[r] ? l:r;
        }
    }
}

int getLCA(int n1, int n2) {
    int l = last[n1], r = last[n2];
    if (l > r) swap(l, r);
    
    int gap = r-l+1;
    int j = logs[gap];
    
    int left = st[l][j], right = st[r - (1 << j) + 1][j];
    int idx = depths[left] < depths[right] ? left : right;

    return nodes[idx];
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> q;
    adj.resize(n+1);

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    nodes.resize(n*2); depths.resize(n*2); last.resize(n+1); 

    tour_idx = 0;
    tour(1, -1, 0);
    buildSparseTable(1);
    
    while (q--) {
        cin >> a >> b;
        int lca = getLCA(a, b);
        cout << depths[last[a]]+depths[last[b]]-depths[last[lca]]*2 << '\n';
    }
}