#define MAX(a,b) ((a > b) ? a : b)
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", arr+i);

    long long cur = arr[0], sum = arr[0];
    for (int i = 1; i < n; i++) {
        cur = MAX(cur+arr[i], arr[i]);

        sum = MAX(sum, cur);
    }
    printf("%lld\n", sum);
}