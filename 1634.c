#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const int INF = 9999998; 
#define MAX_TARGET 1000001 

int memo[MAX_TARGET];

int compare(const void*a, const void*b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    return int_a - int_b;
}

int recur(int rem, int n, int coins[n]) {
    if (rem == 0) return 0;
    if (rem < 0) return INF;

    if (memo[rem] != -1) return memo[rem];

    int min_coins_needed = INF;

    for (int i = 0; i < n; i++) {
        int result = recur(rem - coins[i], n, coins);
        
        if (result != INF) {
            int total_for_this_path = 1 + result;
            min_coins_needed = total_for_this_path < min_coins_needed ? total_for_this_path : min_coins_needed;
        }
    }

    return memo[rem] = min_coins_needed;
}

int main(void) {
    int n, x;
    scanf("%d %d", &n, &x);
    int coins[n];
    for (int i = 0; i < n; i++) scanf("%d", coins+i);
    
    qsort(coins, n, sizeof(int), compare);

    if (x + 1 > MAX_TARGET) {
        printf("-1\n");
        return 1;
    }
    memset(memo, -1, (x + 1) * sizeof(int));

    int s = recur(x, n, coins);
    
    printf("%d", (s == INF) ? -1 : s);
}