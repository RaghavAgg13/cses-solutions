#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
 

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<int> set;
    set.reserve(n); 

    for (int i = 0; i < n; i++) {
        auto it = upper_bound(set.begin(), set.end(), arr[i]);

        if (it == set.end()) {
            set.push_back(arr[i]);
        } else {
            *it = arr[i];
        }
    }
    
    cout << set.size() << endl;
}