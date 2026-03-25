#include <stdio.h>
#include <string.h>
#define max 1001
int memo[max][max];

int pos = 0;
int lcs(int i, int j, int n, int m, int a[], int b[]) {
    if (i == 0 || j == 0) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    if (a[i-1] == b[j-1]) return memo[i][j] = 1+lcs(i-1,j-1,n,m,a,b);

    return memo[i][j] = (lcs(i-1, j, n, m, a, b) > lcs(i, j-1, n, m, a, b) ? lcs(i-1, j, n, m, a, b) : lcs(i, j-1, n, m, a, b));
}

int main(void) {
    int n,m;
    scanf("%d %d", &n, &m);
    memset(memo, -1, sizeof(memo));
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    for (int i = 0; i < m; i++) scanf("%d", b+i);

    int len = lcs(n,m ,n,m,a,b);
    printf("%d\n", len);

    // for (int i = 0; i < max; i++) {
    //     for (int j = 0; j < max; j++) printf("%02d ", memo[i][j]);
    //     printf("\n");
    // }

    int sub[len];
    int idx = len-1, i = n, j = m;

    while (i>0 && j>0) {
        if (a[i-1] == b[j-1]) {
            sub[idx--] = a[i-1];
            i--;
            j--;
        }
        else if (memo[i-1][j] > memo[i][j-1]) i--;
        else j--;
    }

    for (int i = 0; i < len; i++) printf("%d ", sub[i]);
}