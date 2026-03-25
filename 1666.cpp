#include <iostream>
#include <vector>
using namespace std;
 
int n,m,i,x,y,cnt;
vector<int> visited, unique;
vector<vector<int>> arr;

void bfs(int root, int parent) {
    if (visited[root]) return;
    visited[root] = 1;

    for (auto x : arr[root]) {
        if (x != parent) {
            bfs(x, root);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    n++;
    arr.resize(n);

    while (m--) {
        cin >> x >> y;

        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    visited.resize(n);

    cnt = -1;
    for (i = 1; i < n; i++) {
        if (!visited[i]) {
            cnt++;
            unique.push_back(i);
            bfs(i, -1);
        }
    }

    cout << cnt << '\n';
    for (i = 0; i < cnt; i++) {
        cout << unique[i] << ' ' << unique[i+1] << '\n';
    }
}