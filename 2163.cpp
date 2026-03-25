#include <iostream>
using namespace std;
#define ll long long

// 1. Include PBDS headers
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll n,k;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> k;
    ordered_set s;

    for (int i = 0; i < n; i++) s.insert(i+1);
    ll idx = 0;

    while (!s.empty()) {
        idx = (idx+k)%s.size();

        auto it = s.find_by_order(idx);
        cout << *it << ' ';

        s.erase(it);
    }

}