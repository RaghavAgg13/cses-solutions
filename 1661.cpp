#include <iostream>
#include <unordered_map>
#define ll long long
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    ll n,x,i;
    cin >> n >> x;

    unordered_map<ll, ll> prefix;
    prefix.max_load_factor(0.36);
    prefix.reserve(n*4);
    prefix[0] = 1;
    
    ll cur_sum = 0, cnt = 0;
    for (i = 0; i < n; i++) {
        int val;
        cin >> val;
        cur_sum += val;

        cnt += prefix[cur_sum-x];
        prefix[cur_sum]++;
    }

    cout << cnt << endl;
}