#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n, q;
    cin >> n >> q;
 
    vector<ll> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
 
    while (q--) {
        int x,y;
        cin >> x >> y;
        cout << a[y]-a[x-1] << '\n';
    }
}