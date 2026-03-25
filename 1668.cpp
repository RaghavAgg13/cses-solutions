#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
    
int n,m,x,a,b,c;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1, 0), color(n+1, -1);

    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    stack<int> s;
    bool bk = false;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) { 
            vis[i] = 1;
            color[i] = 0;
            s.push(i);
        }
        
        while (!s.empty()) {
            int cur = s.top(); s.pop();
                
            for (auto x : adj[cur]) {
                if (color[x] == color[cur]) {
                    bk = true;
                    break;
                }

                if (!vis[x]) {
                    vis[x] = 1;
                    color[x] = 1-color[cur];
                    s.push(x);
                }
            }
            if (bk) break;
        }
        if (bk) break;
    }

    if (bk) cout << "IMPOSSIBLE\n";
    else {
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) cout << 1 << ' ';
            else cout << color[i]+1 << ' ';
        }
    }
}