#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll n,m,i,j,k;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) cin >> a[i][j];
    }

    vector<char> letters = {'A', 'B', 'C', 'D'};
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < 4; k++) {
                if (a[i][j] != letters[k] && (i ? a[i-1][j] != letters[k] : 1) && (j ? a[i][j-1] != letters[k] : 1)) {
                    a[i][j] = letters[k];
                    break;
                }
            }
        }        
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) cout << a[i][j];
        cout << endl;
    }
}