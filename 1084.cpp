#include <iostream>
using namespace std;

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(void) {
    int n,m,k;
    cin >> n >> m >> k;

    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    qsort(a, n, sizeof(int), cmp);
    qsort(b, m, sizeof(int), cmp);

    int l = 0, r = 0, cnt = 0;
    while (l < n && r < m) {
        if (abs(a[l]-b[r]) <= k) {
            l++;r++;cnt++;
        } else if (a[l] > b[r]) r++;
        else l++;
    }

    cout << cnt;
}