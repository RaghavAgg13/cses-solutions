#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,x,y,i;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3, 0));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        arr[i][0] = x;
        arr[i][1] = y;
        arr[i][2] = i;
    }

    sort(arr.begin(), arr.end());

    for (i = 0; i < n; i++) {
        if (heap.empty()) {
            ans[arr[i][2]] = 1;
            heap.push({arr[i][1], 1});
        }
        else if (heap.top().first < arr[i][0]){
            pair<int, int> tmp = heap.top();
            heap.pop();

            ans[arr[i][2]] = tmp.second;
            heap.push({arr[i][1], tmp.second});
        }
        else {
            ans[arr[i][2]] = heap.size()+1;

            heap.push({arr[i][1], heap.size()+1});
        }
    }

    cout << heap.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}