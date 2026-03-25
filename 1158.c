#include <stdio.h>
#include <stdlib.h>
#define MAXW 100001

int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, x;
    scanf("%d %d", &n, &x);

    long long h[n], s[n];
    for (int i = 0; i < n; i++) scanf("%lld", h+i);
    for (int i = 0; i < n; i++) scanf("%lld", s+i);

    long long dp[x+1];
    for (int i = 0; i <= x; i++) dp[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j-h[i]]+s[i]);
        }
    }

    printf("%lld", dp[x]);
}