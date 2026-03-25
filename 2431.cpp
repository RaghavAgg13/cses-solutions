#include <iostream>
using namespace std;
#define ll long long
 
ll t,n;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> t;
    while (t--) {
        cin >> n;
        n--;

        ll rank = 1, skip = 9, start = 1;
        while (n >= rank*skip) {
            n -= rank*skip;
            rank += 1;
            skip *= 10;
            start *= 10;
        }
        ll no = start + n/rank, rem = n%rank;

        cout << to_string(no)[rem] << "\n";
    }
}