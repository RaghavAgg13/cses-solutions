#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int fact(int n) {
    int ans = 1;
    while (n) ans *= n--;
    return ans;
}

void recur(int idx, char *str, char *a, int n, int *arr) {
    if (idx == n) {
        str[n] += '\0';
        printf("%s\n", str);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i]) continue;
        
        if (i > 0 && a[i] == a[i-1] && arr[i-1] == NULL) continue;

        str[idx] = a[i];
        arr[i] = 1;
        
        recur(idx + 1, str, a, n, arr);
        
        arr[i] = 0;
    }
}

int main(void) {
    char a[9];
    if (scanf("%99s", a) != 1) return 1;

    int n = strlen(a);

    int freq[26] = {0};
    for (int i = 0; i < n; i++) freq[a[i]-'a']++;

    int ans = fact(n);
    for (int i = 0; i < 26; i++) ans /= fact(freq[i]);
    printf("%d\n", ans);

    qsort(a, n, sizeof(char), compare);

    int *arr = calloc(n, sizeof(int));
    char *str = malloc((n + 1) * sizeof(char));

    recur(0, str, a, n, arr);

    free(arr);
    free(str);
}