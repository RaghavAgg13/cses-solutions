#include <iostream>
#include <vector>
using namespace std;
 
int n,m,i,j,x,y,cnt;

vector<bool> visited;
vector<vector<int>> links;

void bfs(int it) {
    visited[it] = true;
    
    for (auto x : links[it]) {
        if(!visited[x]) bfs(x);
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    visited.resize(n*m+m);
    vector<int> tiles;
    links.resize(n*m+m);
 
    vector<string> ch(n);
    vector<pair<int, int>> moves={{0,1},{0,-1},{1,0},{-1,0}};
    cin >> ch[0];
 
    for (i = 0; i < n; i++) {
        if (i+1 < n) cin >> ch[i+1];

        for (j = 0; j < m; j++) {
            if (ch[i][j] == '.') {
                tiles.push_back(i*m+j);
 
                for (auto l : moves) {
                    x = i+l.first, y = j+l.second;

                    if (0 <= x && x < n && 0 <= y && y < m && ch[x][y] == '.') {
                        links[i*m+j].push_back(x*m+y);
                    }
                }
            }
        }
    }
 
    cnt = 0;
    for (auto &t : tiles) {
        if (!visited[t]) {
            cnt++;
            bfs(t);
        }
    }
 
    cout << cnt << '\n';
}