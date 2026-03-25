#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n,cnt,cur,l,r;
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    cnt = 0, cur = 0;
    int l = 0, r = 0;
    while (l < n && r < n) {
        if (a[l] < b[r]) {
            cur++; l++;
            cnt = max(cnt, cur);
        }
        else {
            cur--;
            r++;
        }
    }

    cout << cnt;
}   