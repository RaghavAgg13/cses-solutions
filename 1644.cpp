#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n,a,b,head,tail,sum,tmp,ans;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> a >> b;
    vector<long long> p(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i-1];
    }

    // store all previous sums within i-b to i-a in ascending order.
    // any sum = sum(i) - sum(i-window.start)
    multiset<long long> window;
    long long max_sum = -1e18;

    for (int i = a; i <= n; i++) {
        window.insert(p[i-a]);

        if (i > b) window.erase(window.find(p[i-b-1]));

        max_sum = max(max_sum, p[i] - *window.begin());
    }

    cout << max_sum << '\n';
}