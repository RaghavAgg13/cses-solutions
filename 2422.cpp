#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
 
    ll l = 0, r = n*n;
    while (l < r) {
        ll mid = l + (r-l)/2;
 
        ll no = 0;
        for (int i = 1; i <= n; i++) no += min(n, mid/i);
 
        if (n*n/2+1 <= no) r = mid;
        else l = mid+1;
    }
 
    cout << l << '\n';
}