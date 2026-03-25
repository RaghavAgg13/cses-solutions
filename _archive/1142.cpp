#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr(n), stack(n+1);
    int top = 0;
    ll area = 0;
    
    for (auto &x : arr) cin >> x;
    arr.push_back(0);

    for (int i = 0; i <= n; i++) {
        while (top > 0 && arr[stack[top-1]] >= arr[i]) {
            int h = arr[stack[top-1]];
            top--;
            long long width = top ? i - stack[top-1] - 1 : i;
            area = max(area, width * h);
        }

        stack[top++] = i;
    }

    cout << area << '\n';
}