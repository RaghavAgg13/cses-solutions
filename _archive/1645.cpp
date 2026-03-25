#include <bits/stdc++.h>
using namespace std;
 

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr(n), stack(n);
    int top = 0;

    for (auto &x : arr) cin >> x;

    for (int i = 0; i < n; i++) {
        while (top > 0 && arr[stack[top-1]] >= arr[i]) top--;

        if (top) cout << stack[top-1]+1 << ' ';
        else cout << "0 ";

        stack[top++] = i;
    }
}