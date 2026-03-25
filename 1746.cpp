#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define mod 1000000007
#define ll long long

int n,m;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<vector<ll>> dp(n, vector<ll>(m+2, 0));
    if (arr[0] == 0) {
        for (int i = 1; i <= m; i++) dp[0][i] = 1;
    } else dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                ll ways = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] = ways%mod;
            }
        } else {
            int v = arr[i];
            ll ways = dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1];
            dp[i][v] = ways%mod;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) ans = (ans+dp[n-1][i])%mod;
    cout << ans << endl;
}