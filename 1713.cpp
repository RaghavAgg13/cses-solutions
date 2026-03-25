#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000005;
vector<int> memo(MAX_N, 0);

int t,n,cnt,i;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> t;
    while (t--) {
        cin >> n;

        if (memo[n] != 0) {
            cout << memo[n] << "\n";
            continue;
        }

        cnt = 0;
        for (i = 1; i*i <= n; i++) {
            if (memo[n] != 0) {
                cnt += memo[n];
                n /= memo[n];
            }

            if (n%i == 0) {
                cnt++;
                if (i != n/i) cnt++;
            }
        }
        memo[n] = cnt;

        cout << cnt << '\n';
    }
}