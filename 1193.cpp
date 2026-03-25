#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int n,m,i,j,a1,a2;


vector<pair<char, pair<int, int>>> moves = {{'R', {0,1}},{'L', {0,-1}},{'D',{1,0}},{'U',{-1,0}}};

void bfs(int a1, int a2, string path) {
    
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    queue<pair<int, int>> q;
    vector<vector<char>> from(n, vector<char>(m, 0)); // history of past moves
    vector<vector<bool>> vis(n, vector<bool>(m, false)); //visited check

    vector<string> ch(n);
    for (int i = 0; i < n; i++) cin >> ch[i];
 
    string ans = "";

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (ch[i][j] == 'A') {
                q.push({i, j});
                vis[i][j] = true;
                a1 = i, a2 = j;
                break;
            }
        }
    }
    
    // bfs start
    bool found = false;
    int end_x, end_y;

    while(!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        if (ch[cx][cy] == 'B') {
            found = true;
            end_x = cx, end_y = cy;
            break;
        }

        for (auto l : moves) {
            int x = cx + l.second.first, y = cy + l.second.second;

            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (ch[x][y] != '#' && !vis[x][y]) {
                    vis[x][y] = true;
                    from[x][y] = l.first;
                    q.push({x, y});
                }
            }
        }
    }

    if (found) {
        while (end_x != a1 || end_y != a2) {
            char dir = from[end_x][end_y];
            ans += dir;
            
            for (auto l : moves) {
                if (l.first == dir) {
                    end_x -= l.second.first;
                    end_y -= l.second.second;
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());

        cout << "YES\n";
        cout << ans.length() << '\n';
        cout << ans << '\n';
    }
    else cout << "NO" << '\n';
}