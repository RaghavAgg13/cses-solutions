#include <iostream>
#include <vector>
using namespace std;

int n,m,q;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> q;
    vector<vector<int>> arr(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;

            arr[i][j] = (c == '*') +arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }

    int x1,y1,x2,y2;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << arr[x2][y2]-arr[x1-1][y2]-arr[x2][y1-1]+arr[x1-1][y1-1] << '\n';
    }
}