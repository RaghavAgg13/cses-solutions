#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define mod 1000000007
#define max 1000001
long long memo[max];

int compare(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    return int_a-int_b;
}

long long recur(int sum, int x, int n, int coins[n]) {
    if (sum == x) return 1;
    if (sum > x) return 0;

    if (memo[sum] != -1) return memo[sum];

    long long s = 0;
    for (int i = 0; i < n; i++) {
        s = (s + recur(sum + coins[i], x, n, coins)) % mod;
    }
    return memo[sum] = s;
}

int main(void) {
    int n,x;
    scanf("%d %d", &n, &x);
    int coins[n];
    for (int i = 0; i < n; i++) scanf("%d", coins+i);
    qsort(coins, n, sizeof(int), compare);

    memset(memo, -1, (x+1)*sizeof(long long));

    long long ways = recur(0, x, n, coins);
    printf("%lld\n", ways);
}