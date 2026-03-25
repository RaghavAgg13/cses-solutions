#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, k; 

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> k;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    multiset<int> ends;
    int cnt = 0;

    for (int i = 0; i < k; i++) ends.insert(0);
    for (int i = 0; i < n; i++) {
        auto it = ends.upper_bound(arr[i].first);

        if (it != ends.begin()) {
            it--;
            cnt++;

            ends.erase(it);
            ends.insert(arr[i].second);
        }
    }

    cout << cnt << '\n';
}