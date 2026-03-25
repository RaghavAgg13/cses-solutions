#include <stdio.h>
int m = __INT_MAX__;

int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }

int recur(int n, int left, int right, int arr[n], int first, int second) {
    if (left >= right) m = max(m, first);

    int n1 = recur(n, left+1, right, arr, first+arr[left], second);
    int n2 = recur(n, left, right-1, arr, first, second+arr[right]);
    return min(n1, n2);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", arr+i);

    int a = recur(n, 0, n-1, arr, 0, 0);
    printf("%d", a);
}