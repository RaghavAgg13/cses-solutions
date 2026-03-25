#include <iostream>
using namespace std;
#define ll long long

ll x1, y1, x2, y2, x3, y3;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        ll val1 = (x2 - x1) * (y3 - y1), val2 = (y2 - y1) * (x3 - x1);

        if (val1 == val2) cout << "TOUCH\n";
        else if (val1 > val2) cout << "LEFT\n";
        else cout << "RIGHT\n";
    }
}