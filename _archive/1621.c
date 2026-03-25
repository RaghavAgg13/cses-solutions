#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(void) {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", arr+i);
    qsort(arr, n, sizeof(int), cmp);

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) cnt++;
    }

    printf("%d\n", cnt);
}