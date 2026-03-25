#include <iostream>
using namespace std;

const int MAXN = 100001;

int n, idx;
int ans[MAXN];
int in_idx[MAXN];
int preOrder[MAXN];

void solve(int preIdx, int l, int r) {
    if (l > r) return;

    ans[idx--] = preOrder[preIdx];
    if (l == r) return;

    int inIdx = in_idx[preOrder[preIdx]];

    solve(preIdx+(inIdx-l)+1, inIdx+1, r);
    solve(preIdx+1, l, inIdx-1);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n;

    for (int i = 0; i < n; i++) cin >> preOrder[i];

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        in_idx[tmp] = i;
    }

    idx = n-1;
    solve(0, 0, n-1);

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}