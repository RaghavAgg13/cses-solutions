#include <iostream>
#include <set>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int x, n;
    cin >> x >> n;

    int val;

    set<int> seen = {0, x};
    multiset<int> passages = {x};

    for (int i = 0; i < n; i++) {
        cin >> val;
        
        auto right = seen.upper_bound(val);
        auto left = prev(right);

        passages.erase(passages.find(*right - *left));

        passages.insert(*right-val);
        passages.insert(val-*left);
        seen.insert(val);

        cout << *passages.rbegin() << ' ';
    }
}