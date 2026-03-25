#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int l = 1, r = 1000000000;

    while (l < r) {
        int mid = l + (r-l)/2;

        cout << "? " << mid << endl;
        string out;
        cin >> out;

        if (out == "YES") l = mid+1;
        else r = mid;
    }

    cout << "! " << l << '\n';
}