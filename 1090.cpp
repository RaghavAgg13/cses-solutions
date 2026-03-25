#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n,x,cnt,l,r;
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> x;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
 
    sort(arr.begin(), arr.end());
    
    cnt = 0, l = 0, r = n-1;
    while (l <= r) {
        if (arr[l]+arr[r] > x) { cnt++;r--; }
        else if (arr[l]+arr[r] <= x) { cnt++;r--;l++; }
    }

    cout << cnt;
}   