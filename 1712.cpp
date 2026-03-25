#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define mod 1000000007

ll n,a,b,c;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;

        a %= mod; b %= mod-1;

        ll x = 1;
        
        while (c > 0) {
            if (c%2) {
                x = (x*b) % (mod-1);
            }
            b = (b*b) % (mod-1);
            c /= 2;
        }

        b = x;
        x = 1;

        while (b > 0) {
            if (b%2) {
                x = (x*a)%mod;
            }

            a = (a*a)%mod;
            b /= 2;
        }

        cout << x << '\n';
    }
}   