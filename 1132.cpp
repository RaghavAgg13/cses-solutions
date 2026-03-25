#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector<vector<int>> adj;
vector<int> ans;
 
int n,a,b,dist,i,u,v;
 
void dfs(int root, int parent, int d) {
    if (d > dist) {
        dist = d;
        a = root;
    }
 
    for (auto x : adj[root]) {
        if (x != parent) dfs(x, root, d+1);
    }
}
 
void get(int root, int parent, int d) {
    if (d > ans[root]) ans[root] = d;
 
    for (auto x : adj[root]) {
        if (x != parent) get(x, root, d+1);
    }
}
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n;
    adj.resize(n+1, vector<int>());
    ans.resize(n+1, 0);
 
    for (i = 0; i < n-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dist = -1;
    dfs(1, -1, 0);
    get(a, -1, 0);
    
    int max_d = -1;
    for (int i = 1; i <= n; i++) {
        if (ans[i] > max_d) {
            max_d = ans[i];
            b = i;
        }
    }
    
    get(b, -1, 0);
 
    for (i = 1; i <= n; i++) cout << ans[i] << ' ';
}