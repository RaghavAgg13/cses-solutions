#include <iostream> 
#include <vector>
using namespace std;
 
int n,m,x,y,i;
vector<int> ans, vis;
vector<vector<int>> arr;

void dfs(int root, int parent, vector<int>& path) {
    if (ans.size()) return;

    if (vis[root]) {
        // found loop
        ans.push_back(root);
        for (int i = path.size()-1; i>= 0; i--) {
            ans.push_back(path[i]);
            if (path[i] == root) break;
        }
        return;
    }

    vis[root] = 1;
    path.push_back(root);

    for (auto x : arr[root]) {
        if (x != parent) {
            dfs(x, root, path);
            if (!ans.empty()) return;
        }
    }

    path.pop_back(); //backtracking
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    n++;
    
    arr.resize(n);
    ans.clear();
    vis.resize(n);
    
    while(m--) {
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    vector<int> path;

    for (i = 1; i < n; i++) {
        if (!vis[i] && ans.empty()) {
            dfs(i, -1, path);
        }
    }

    if (ans.size()) {
        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
    else cout << "IMPOSSIBLE\n";
    
}