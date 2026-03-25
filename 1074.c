#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) { return (*(int*)a - *(int*)b); }

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", arr+i);

    qsort(arr, n, sizeof(int), compare);
    int median = arr[n/2];
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += llabs(arr[i]-median);
    }

    printf("%lld\n", ans);
}