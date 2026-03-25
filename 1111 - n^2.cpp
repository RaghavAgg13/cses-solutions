#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string a;
    cin >> a;
    int n = a.length();

    int dp[n][n], max_j = 0, best_i = 0;
    
    for (int i = 0; i < n; i++) dp[i][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = 0;

            if (i-j >= 0 && a[i] == a[i-j]) {
                if (j == 1 || dp[i-1][j-2] == 1) {
                    dp[i][j] = 1;

                    if (j > max_j) {
                        max_j = j;
                        best_i = i;
                    }
                }
            }
        }
    }

    cout << a.substr(best_i-max_j, max_j+1) << '\n';  
}   