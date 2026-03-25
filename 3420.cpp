#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) cin >> a[i];

    long long cnt = 0;
    int l = 0, r = 0;
    while (r < n) {
        freq[a[r]]++;

        while (freq[a[r]] > 1) {
            freq[a[l]]--;
            l++;
        }

        cnt += r-l+1;
        r++;
    }

    cout << cnt << endl;
}