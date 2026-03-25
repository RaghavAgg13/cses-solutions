#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void * b) { return (*(int*)a - *(int*)b); }

int main(void) {
    int n,x;
    scanf("%d %d", &n, &x);
    
    int arr[n], sort[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        sort[i] = arr[i];
    }

    int left = 0, right = n-1;
    qsort(sort, n, sizeof(int), compare);

    while (left < right) {
        if (sort[left] + sort[right] == x) {
            int a = -1, b = -1;
            for (int i = 0; i < n; i++) {
                if (arr[i] == sort[left]) {
                    a = i;
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (arr[i] == sort[right] && i != a) {
                    b = i;
                    break;
                }
            }

            printf("%d %d\n", a+1, b+1);
            return 0;
        } else if (sort[left] + sort[right] > x) right--;
        else left++;
    }
    printf("IMPOSSIBLE\n");
}