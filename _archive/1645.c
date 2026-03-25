#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    int arr[n], stack[n], ans[n], top = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        ans[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        while (top > 0 && arr[stack[top-1]] >= arr[i]) top--;

        if (top) ans[i] = stack[top-1] + 1;

        stack[top++] = i;
    }

    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}