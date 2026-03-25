#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    ll x0, y0, x1, y1, x2, y2, area = 0;

    cin >> x0 >> y0;
    
    x1 = x0;
    y1 = y0;

    for (int i = 1; i < n; i++) {
        cin >> x2 >> y2;
        
        area += (x1 * y2 - x2 * y1);
        
        x1 = x2;
        y1 = y2;
    }

    area += (x1 * y0 - x0 * y1);

    cout << abs(area) << "\n";
}