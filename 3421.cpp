#include <iostream>
#include <map>
using namespace std;
#define ll long long
const int mod = 1e9+7;

ll n,x;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n;
    map<int, int> freq;
    
    while (n--) {
        cin >> x;
        freq[x]++;
    }

    ll ans = 1;
    for (auto [val, cnt] : freq) {
        ans = (ans*(cnt+1))%mod;
    }

    cout << (ans-1)%mod;
}