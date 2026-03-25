#include <bits/stdc++.h>
using namespace std;
#define ll long long
 

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    ll n, t;
    cin >> n >> t;
    
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
 
    ll mid, l = 0, r = t*1e9;
    // the array of times is sorted, and hence binary searchable
    while (l < r) {
        mid = l + (r-l)/2;
 
        // getting products created for a particular time
        ll prod = 0;
        for (ll x : a) {
            prod += mid/x;
            if (prod >= t) break;
        }
            
        if (prod >= t) r = mid;
        else l = mid+1;
    }
 
    cout << l;
}