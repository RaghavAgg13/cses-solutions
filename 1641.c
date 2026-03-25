#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(void) {
    int n,x;
    scanf("%d %d", &n, &x);

    int arr[n], target, sort[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        sort[i] = arr[i];
    }

    qsort(sort, n, sizeof(int), cmp);

    for (int i = 0; i < n-2; i++) {
        int left = i+1, right = n-1;

        while (left < right) {
            target = sort[i] + sort[left] + sort[right];
            if (target == x) {
                // printf("%d %d %d\n", i+1, left+1, right+1);
                int a = -1,b = -1,c = -1;
                for (int j = 0; j < n; j++) {
                    if (arr[j] == sort[i]) {
                        a = j;
                        break;
                    }
                }
                for (int j = 0; j < n; j++) {
                    if (arr[j] == sort[left] && j != a) {
                        b = j;
                        break;
                    }
                }
                for (int j = 0; j < n; j++) {
                    if (arr[j] == sort[right] && j != a && j != b) {
                        c = j;
                        break;
                    }
                }
                printf("%d %d %d\n", a+1, b+1, c+1);
                
                return 0;
            }
            else if (target > x) right--;
            else left++;
        }
    }
    printf("IMPOSSIBLE\n");
}