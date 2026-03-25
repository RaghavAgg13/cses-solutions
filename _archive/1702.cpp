#include <iostream>
#include <vector>
using namespace std;

int n, idx;
vector<int> ans(n), in_map(100001);

void recur(int pos, int l, int r, const vector<int> &preOrder) {
    if (l > r) return;

    ans[idx--] = preOrder[pos];

    int inIdx = in_map[preOrder[pos]];

    recur(pos+(inIdx-l)+1, inIdx+1, r, preOrder);
    recur(pos+1, l, inIdx-1, preOrder);
}
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    ans.resize(n);

    vector<int> preOrder(n), inOrder(n);
    for (auto &x : preOrder) cin >> x;
    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
        in_map[inOrder[i]] = i;
    }

    idx = n-1;
    recur(0, 0, n-1, preOrder);

    for (auto x : ans) cout << x << ' ';
    cout << endl;
}