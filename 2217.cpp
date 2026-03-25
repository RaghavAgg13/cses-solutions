#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n+1), pos(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int cnt = 1;
    for (int i = 2; i < n+1; i++) {
        if (pos[i] < pos[i-1]) cnt++;
    }

    auto change = [&](int k, int c) {
        if (k <= n && pos[k - 1] > pos[k]) cnt += c;
    };

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        change(a[x], -1);
        if (a[x] + 1 != a[y]) change(a[x] + 1, -1);
        change(a[y], -1);
        if (a[y] + 1 != a[x]) change(a[y] + 1, -1);
        swap(a[x], a[y]);
        pos[a[x]] = x;
        pos[a[y]] = y;
        change(a[x], 1);
        if (a[x] + 1 != a[y]) change(a[x] + 1, 1);
        change(a[y], 1);
        if (a[y] + 1 != a[x]) change(a[y] + 1, 1);
        cout << cnt << "\n";
    }
}