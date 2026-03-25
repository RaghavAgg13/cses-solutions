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

    for (int i = 0; i < n-3; i++) {
        for (int j = i+1; j < n-2; j++) {
            int left = j+1, right = n-1;

            while (left < right) {
                target = sort[i] + sort[j] + sort[left] + sort[right];
                if (target == x) {
                    // printf("%d %d %d\n", i+1, left+1, right+1);

                    // get a,b,c,d positions from original unsorted array
                    // Happens in linear time same as 2-pointer search to no additional overhead in terms of complexity.
                    int a = -1,b = -1,c = -1, d = -1;
                    for (int k = 0; k < n; k++) {
                        if (arr[k] == sort[i]) {
                            a = k;
                            break;
                        }
                    }
                    for (int k = 0; k < n; k++) {
                        if (arr[k] == sort[left] && k != a) {
                            b = k;
                            break;
                        }
                    }
                    for (int k = 0; k < n; k++) {
                        if (arr[k] == sort[right] && k != a && k != b) {
                            c = k;
                            break;
                        }
                    }
                    for (int k = 0; k < n; k++) {
                        if (arr[k] == sort[j] && k != a && k != b && k != c) {
                            d = k;
                            break;
                        }
                    }

                    printf("%d %d %d %d\n", a+1, b+1, c+1, d+1);
                    
                    return 0;
                }
                else if (target > x) right--;
                else left++;
            }
        }
    }
    printf("IMPOSSIBLE\n");
}