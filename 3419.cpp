#include <iostream>
using namespace std;

int n,i;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (i^j) << ' ';
        }
        cout << '\n';
    }
}