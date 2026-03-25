#include <stdio.h>
#include <stdlib.h>

#define max_sum 1000001
#define max_n 101
#define MOD 1000000007

int dp[max_n][max_sum];

int main(void) {
    int n, x;
    scanf("%d %d", &n, &x);
    
    int coins[n+1];
    for (int i = 1; i <= n; i++) scanf("%d", coins+i);

    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        int current_coin = coins[i];
        
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            
            if (j >= current_coin) {
                dp[i][j] += dp[i][j - current_coin];
                
                if (dp[i][j] >= MOD) dp[i][j] -= MOD;
            }
        }
    }

    printf("%d", dp[n][x]);
}