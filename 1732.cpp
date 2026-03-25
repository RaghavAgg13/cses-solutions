#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mod 100000007
#define ll long long

int n,x,n1,n2;
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    string a;
    cin >> a;
    n = a.length();

    vector<int> arr(n+1, 0);
    
    ll key = 0, mult = 1;
    for (int i = n-1; i > 0; i--) {
        key = (key*26 + (a[i]-'a'+1))%mod;

        arr[n-i] = key;
    }

    key = 0;
    vector<int> borders;
    for (int i = 0; i < n-1; i++) {
        key += (a[i]-'a'+1)*(mult);
        
        mult = (mult*26)%mod;
        key %= mod;

        if (arr[i+1] == key) {
            borders.push_back(i+1);
        }
    }

    for (auto x : borders) cout << x << ' ';
}   