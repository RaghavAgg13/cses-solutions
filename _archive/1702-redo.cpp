#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int n, idx;
vector<int> ans, in_idx(100001);

void solve(int preIdx, int l, int r, const vector<int> &preOrder) {
    if (l > r) return;

    ans[idx--] = preOrder[preIdx];

    int inIdx = in_idx[preOrder[preIdx]];

    solve(preIdx+(inIdx-l)+1, inIdx+1, r, preOrder);
    solve(preIdx+1, l, inIdx-1, preOrder);
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
        in_idx[inOrder[i]] = i;
    }

    idx = n-1;
    solve(0, 0, n-1, preOrder);

    for (auto x : ans) cout << x << ' ';
    cout << endl;
}