#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
 
int get_divs(int n, const vector<ll>& arr, ll s) {
    ll k = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum+arr[i] <= s) sum += arr[i];
        else {
            k++;
            sum = arr[i];
        }
    }
    return k;
}
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    ll n,k,max_val=0,sum=0;
    cin >> n >> k;
 
    vector<ll> arr(n);
    for (auto &x : arr) {
        cin >> x;
        max_val = max(max_val, x);
        sum += x;
    }
 
    ll ans = sum;
    
    ll l = max_val, r = sum;
    while (l <= r) {
        ll mid = l + (r-l)/2;
 
        if (get_divs(n, arr, mid) <= k) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
 
    cout << ans << endl;
}