#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define mod 1000000007
#define ll long long

int t,n,cnt,i;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp%2 == 1) res = (res*base)%mod;
        base = (base*base)%mod;
        exp /= 2;
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string a;
    cin >> a;
    vector<int> freq(26, 0);
    int n = a.length();

    for (int i = 0; i < n; i++) freq[a[i]-'a']++;

    ll prod = 1;
    int pos = 0;

    for (int i = 1; i <= n; i++) {
        prod = (prod*i) % mod;

        while (pos < 26 && freq[pos] == 0) pos++;

        if (pos < 26) {
            prod = (prod * power(freq[pos], mod-2))%mod;
            freq[pos]--;
        }
    }

    cout << prod;
}