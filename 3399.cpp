#include <vector>
#include <iostream>
using namespace std;
#define ll long long
 
int t,n,a,b;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> t;
 
    while (t--) {
        cin >> n >> a >> b;
 
        // extreme base/edge case
        if (a+b > n || (a == 0 && b > 0) || (a > 0 && b == 0)) cout << "NO\n";
        else {
            // now a+b <= n
 
            vector<int> x(n), y(n);
            for (int i = a+b; i < n; i++) {
                x[i] = i+1;
                y[i] = i+1;
            }
            for (int i = 0; i < a; i++) {
                x[i] = i+1;
                y[i] = i+1+b;
            }
            for (int i = a; i < a+b; i++) {
                x[i] = i+1;
                y[i] = i-a+1;
            }
 
            cout << "YES" << endl;
            for (auto it : y) cout << it << ' ';
            cout << endl;
            for (auto it : x) cout << it << ' ';
            cout << endl;
        } 
    }
}