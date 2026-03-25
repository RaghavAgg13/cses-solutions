#include <stdio.h>
#include <string.h>
#define mod 1000000007
#define max 1000

int memo[max][max];

int recur(int x, int y, int n, char arr[n][n]) {
    if (x >= n || y >= n) return 0;
    if (arr[x][y] == '*') return 0;
    if (memo[x][y] != -1) return memo[x][y];
    if (x == n-1 && y == n-1) return 1;
    
    int ans = 0;
    ans += recur(x+1, y, n, arr)%mod;
    ans += recur(x, y+1, n, arr)%mod;
    return memo[x][y] = ans%mod;
}

int main(void) {
    int n;
    scanf("%d", &n);

    char arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf(" %c", *(arr+i)+j);
    }

    memset(memo, -1, sizeof(memo));

    int moves = recur(0,0,n,arr);
    printf("%d", moves);
}