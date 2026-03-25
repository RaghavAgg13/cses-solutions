#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll n,q,x;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> q;
    vector<ll> arr(n+1);
    
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        arr[i] = x^arr[i-1];
    }

    int l,r;
    while (q--) {
        cin >> l >> r;

        cout << (arr[r]^arr[l-1]) << '\n';
    }

}