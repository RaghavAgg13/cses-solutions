#include <stdio.h>
#define mod 1000000007
#define int long long

int main(void) {
    int t;
    int a,b;

    scanf("%lld", &t);
    for (int i = 0; i < t; i++) {
        scanf("%lld %lld", &a, &b);

        int ans = 1;
        a %= mod;

        while (b > 0) {
            if (b%2 == 1) ans = (ans*a)%mod;

            a = (a*a)%mod;
            b /= 2;

        }
        printf("%lld\n", ans);
    }
    return 0;
}