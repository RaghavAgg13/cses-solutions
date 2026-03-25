#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;

    sort(a.begin(), a.end());

    int l = 0, cnt = 1, i = 1;
    while (i < n) {
        if (a[l].first <= a[i].second) { l = i;cnt++;i++; }
        else i++;
    }
    cout << cnt << endl;
}