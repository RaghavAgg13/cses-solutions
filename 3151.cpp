#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long

ll n;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> b(n);
    b = a;
    sort(b.begin(), b.end());

    unordered_map<int, int> m;
    m.reserve(n/2);
    m.max_load_factor(0.5);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int dist = distance(b.begin(), lower_bound(b.begin(), b.end(), a[i]));
        dist += m[a[i]];
        m[a[i]]++;
        cnt = max(cnt, i-dist);
    }   
    cout << cnt << endl;

}