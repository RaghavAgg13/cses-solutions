#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
#define ll long long

int n,k,i;

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;

    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    vector<int> queue(n);
    int head = 0, tail = 0;

    ll area = 0; 

    for (i = 0; i < n; i++) {
        if (tail-head && queue[head] <= i-k) head++;
        while (tail-head && arr[queue[tail-1]] <= arr[i]) tail--;

        queue[tail++] = i;

        if (i >= k-1) {
            cout << arr[queue[head]] << ' ';
        }
    }
}