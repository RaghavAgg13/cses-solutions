#include <stdio.h>

int main(void) {
    int n,x;
    scanf("%d %d", &n, &x);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", arr+i);

    int cnt = 0, cur = 0, left = 0;
    for (int i = 0; i < n; i++) {
        cur += arr[i];
        while (cur >= x) {
            if (cur == x) cnt++;
            cur -= arr[left++];
        }
    }
    printf("%d\n", cnt);
}