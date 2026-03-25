#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int n,m,x,y;
vector<int> ans;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    n++;
    vector<vector<int>> arr(n);

    while (m--) {
        cin >> x >> y;

        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    queue<int> q;
    vector<int> from(n); // history of past moves
    vector<bool> vis(n); //visited check

    // bfs start
    q.push(1);
    vis[1] = true;
    bool found = false;
    int end;

    while(!q.empty()) {
        int a = q.front();
        q.pop();

        if (a == n-1) {
            found = true;
            end = a;
            break;
        }

        for (auto l : arr[a]) {
            if (!vis[l]) {
                vis[l] = true;
                from[l] = a;
                q.push(l);
            }
        }
    }

    if (found) {
        ans.push_back(end);
        while (end != 1) {
            int dir = from[end];
            ans.push_back(dir);
            end = dir;
        }
        reverse(ans.begin(), ans.end());

        cout << ans.size() << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    } 
    else cout << "IMPOSSIBLE\n";
}