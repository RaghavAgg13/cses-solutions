#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int t,n;
vector<int> map1, map2;
vector<vector<int>> arr;

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid  = l + (r-l)/2;

    merge_sort(l, mid);
    merge_sort(mid+1, r);

    vector<vector<int>> stack(r-l+1);
    int top = 0;
    int i = l, j = mid+1;

    while (i <= mid && j <= r) {
        if (arr[i][1] < arr[j][1]) {
            if (arr[l][1] >= arr[j][1]) map2[arr[j][2]] += (i-l);
            stack[top++] = arr[j++];
            
        } else {
            if (arr[i][1] >= arr[r][1]) map1[arr[i][2]] += (r-j+1);
            stack[top++] = arr[i++];
        }
    }

    // move elements to stack and then push back to arr
    while (i <= mid) {
        if (arr[i][1] >= arr[r][1]) map1[arr[i][2]] += (r-mid);
        stack[top++] = arr[i++];
    }
    while (j <= r) {
        if (arr[l][1] >= arr[j][1]) map2[arr[j][2]] += (mid-l+1);
        stack[top++] = arr[j++];
    }

    for (int k = 0; k < top; k++) arr[l+k] = stack[k];
} 

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n, vector<int>(3));

    // input
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }

    // logic
    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b) { if (a[0] == b[0]) return a[1] > b[1]; return a[0] < b[0]; });

    map1.resize(n, 0);
    map2.resize(n, 0);
    
    merge_sort(0, n-1);

    for (auto x : map1) cout << x << ' ';
    cout << '\n';
    for (auto x : map2) cout << x << ' ';
    cout << '\n';
}