#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = 0, r = 0;

    int cnt = 0, m = 0;
    while (l < n && r < n) {
        if (a[l] < b[r]) {
            m++; l++;
            cnt = max(cnt, m);
        } else {
            m--; r++;
        }
    }

    cout << cnt;
}