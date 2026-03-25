#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int n,k,i;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> k;
    
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    
    unordered_map<int, int> freq;
    freq.reserve(k * 2);
    freq.max_load_factor(0.7);
    
    long long cnt = 0;
    for (i = 0; i < k; i++) {
        if (++freq[arr[i]] == 1) cnt++;
    }

    for (i = k; i < n; i++) {
        cout << cnt << ' ';

        if (freq[arr[i-k]]-- == 1) cnt--;
        if (freq[arr[i]]++ == 0) cnt++;
    }
    cout << cnt << '\n';
}