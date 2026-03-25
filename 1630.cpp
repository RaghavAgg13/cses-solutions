#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());

    long long time = 0, score = 0;
    for (int i = 0; i < n; i++) {
        time += a[i].first;
        score += a[i].second-time;
    }

    cout << score << '\n';
}