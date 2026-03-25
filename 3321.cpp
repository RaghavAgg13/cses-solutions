#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
    
int n, k;
int x,a,b,c;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> x >> a >> b >> c;

    int min_xor = 0;

    vector<int> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) arr[i] = (1LL*arr[i-1]*a+b)%c;

    vector<int> deque(n);
    int head = 0, tail = 0;

    for (int i = 0; i < n; i++) {
        if (tail-head && deque[head] <= i-k) head++;

        while (tail-head && arr[deque[tail-1]] >= arr[i]) tail--;

        deque[tail++] = i;

        if (i >= k-1) min_xor ^= arr[deque[head]];
    }

    cout << min_xor << endl;
}