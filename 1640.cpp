#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
int n,x,n1,n2;
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> x;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
 
    map<int, int> seen;

    n1 = -1;
    for (int i = 0; i < n; i++) {
        if (seen.find(x-arr[i]) != seen.end()) {
            n1 = i;
            n2 = seen[x-arr[i]];
            break;
        }
        else seen[arr[i]] = i;
    }

    if (n1 == -1) cout << "IMPOSSIBLE\n";
    else {
        cout << n1+1 << ' ' << n2+1 << '\n';
    }
}   