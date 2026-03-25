#include <stdio.h>
#include <string.h>
#define mod 1000000007
#define max 1000001

int memo[max];

int recur(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (memo[n] != -1) return memo[n]; 

    long long ans = 0;
    for (int i = 1; i < 7; i++) {
        if (n >= i) {
            ans += recur(n-i)%mod;
        }
    }
    ans %= mod;
    return memo[n] = ans;
}

int main(void) {
    int n;
    scanf("%d", &n);

    memset(memo, -1, sizeof(memo));

    int s = recur(n);
    printf("%d", s);
}