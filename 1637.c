#include <stdio.h>
#include <string.h>
#include <limits.h>
#define max 1000001
int memo[max];

int min(int a, int b) {
    return a < b ? a : b;
}

int recur(int n) {
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];

    int s = INT_MAX;
    int temp = n;
    while (temp > 0) {
        int digit = temp%10;
        temp /= 10;

        if (digit != 0) {
            int sub_result = recur(n - digit);
            if (sub_result != INT_MAX) s = min(s, sub_result + 1);
        }
    }
    return memo[n] = s;
}

int main(void) {
    int n;
    scanf("%d", &n);
    memset(memo, -1, sizeof(memo));

    printf("%d\n", recur(n));
}