#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n,cnt;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    sort(arr.begin(), arr.end());
    
    cnt = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i-1]) cnt++;
    }
    
    cout << cnt;
}