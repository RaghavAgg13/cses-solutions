#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int, int>
int n,x,y,i,idx;

void swap(pii &a, pii &b) {
    pii tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3, 0));
    vector<pii> heap(n);
    vector<int> ans(n);
    int size = 0;
 
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
 
        arr[i][0] = x;
        arr[i][1] = y;
        arr[i][2] = i;
    }
 
    sort(arr.begin(), arr.end());
 
    for (i = 0; i < n; i++) {
        if (!size) {
            ans[arr[i][2]] = 1;
            heap[size++] = {arr[i][1], 1};
        }
        else if (heap[0].first < arr[i][0]){
            ans[arr[i][2]] = heap[0].second;
 
            // deletion + insertion within same step
            heap[0].first = arr[i][1];
            idx = 0;
            
            while ((idx*2+1 < size && heap[idx*2+1] < heap[idx]) || (idx*2+2 < size && heap[idx*2+2] < heap[idx])) {
                if (idx*2+2 >= size || heap[idx*2+2] > heap[idx*2+1]) {
                    swap(heap[idx*2+1], heap[idx]);
                    idx = idx*2+1;
                }
                else {
                    swap(heap[idx*2+2], heap[idx]);
                    idx = idx*2+2;
                }
            }
        }
        else {
            ans[arr[i][2]] = size+1;
            heap[size] = {arr[i][1], size+1};
 
            idx = size++;
            
            while (idx && heap[(idx-1)/2] > heap[idx]) {
                swap(heap[(idx-1)/2], heap[idx]);
                idx = (idx-1)/2;
            }
        }
    }
 
    cout << size << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}