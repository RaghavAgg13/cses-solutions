#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define mod 100000007
#define ll long long

int n,m;
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string a,b;
    cin >> a;
    cin >> b;
    n = a.length(), m = b.length();

    ll target = 0;
    for (int i = 0; i < m; i++) target = (target*26 + b[i]-'a'+1)%mod;
    
    ll key = 0, cnt = 0;
    for (int i = 0; i < m-1; i++) key = (key*26 + a[i]-'a'+1)%mod;

    ll p = 1;
    for (int i = 0; i < m - 1; i++) p = (p * 26) % mod;

    for (int i = m-1; i < n; i++) {
        key = (key*26 + a[i]-'a'+1)%mod;
        
        if (key == target) cnt++;
        key = (key - (a[i - m + 1] -'a'+1)*p%mod + mod) % mod;
    }
    
    cout << cnt << '\n';
}   