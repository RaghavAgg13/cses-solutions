#include <bits/stdc++.h>
using namespace std;

int n,k,x,a,b,c,i;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> k >> x >> a >> b >> c;
 
    
    vector<int> arr(n);
    arr[0] = x;
    for (i = 1; i < n; i++) arr[i] = (1LL*arr[i-1]*a+b)%c;
    
    long long sum = 0, xor_s;
    for (i = 0; i < k; i++) sum += arr[i];
    xor_s = sum;
 
    for (i = k; i < n; i++) {
        sum += arr[i]-arr[i-k];
        xor_s ^= sum;
    }
 
    cout << xor_s << endl;
}