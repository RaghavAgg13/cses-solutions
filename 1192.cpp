#include <iostream>
#include <vector>
using namespace std;
 
int n,m,i,j,cnt;

vector<string> ch;
vector<pair<int, int>> moves={{0,1},{0,-1},{1,0},{-1,0}};

void bfs(int a1, int a2) {
    ch[a1][a2] = '#';
    
    for (auto l : moves) {
        int x = a1+l.first, y = a2+l.second;

        if (x >= 0 && x < n && y >= 0 && y < m) {
            if (ch[x][y] == '#') continue;
            
            bfs(x,y);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    ch.resize(n);
    for (int i = 0; i < n; i++) cin >> ch[i];
 
    cnt = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (ch[i][j] == '.') {
                cnt++;
                bfs(i,j);
            }
        }
    }

    cout << cnt << '\n';
}