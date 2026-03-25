#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<pair<int, int>> tile;
vector<vector<bool>> visited;

void bfs(vector<vector<vector<pair<int, int>>>>& links, pair<int, int> it) {
    visited[it.first][it.second] = true;
    
    for (auto x : links[it.first][it.second]) {
        if (!visited[x.first][x.second]) bfs(links, x);
    }   
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,m;
    cin >> n >> m;
    vector<string> ch(n);
    
    visited.assign(n, vector<bool>(m, false));
    vector<vector<vector<pair<int, int>>>> links(n, vector<vector<pair<int, int>>>(m));

    for (int i = 0; i < n; i++) cin >> ch[i];

    tile.clear();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ch[i][j] == '.') {
                tile.push_back({i,j});   

                if (i+1 < n && ch[i+1][j] == '.') {
                    links[i][j].push_back({i+1,j});
                }
                if (j+1 < m && ch[i][j+1] == '.') {
                    links[i][j].push_back({i,j+1});
                }
                if (i-1 >= 0 && ch[i-1][j] == '.') {
                    links[i][j].push_back({i-1,j});
                }
                if (j-1 >= 0 && ch[i][j-1] == '.') {
                    links[i][j].push_back({i,j-1});
                }
            }
        }
    }

    int cnt = 0;
    for (auto &t : tile) {
        if (!visited[t.first][t.second]) {
            cnt++;
            bfs(links, t);
        }
    }

    cout << cnt << endl;
}