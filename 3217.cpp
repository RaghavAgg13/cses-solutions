#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    
    vector<vector<int>> a(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    a[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == -1) {
                a[nx][ny] = a[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}