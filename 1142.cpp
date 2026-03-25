#include <iostream>
#include <vector>
using namespace std;
 
int n,top;
long long area;
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    vector<int> arr(n), Q(n+1);
    top = 0;

    for (auto &x : arr) cin >> x;
    arr.push_back(0);

    for (int i = 0; i <= n; i++) {
        while (top && arr[Q[top-1]] >= arr[i]) {
            int h = arr[Q[top-1]];
            top--;
            long long w = (top) ? i-Q[top-1]-1 : i;

            area = max(area, h*w);
        }

        Q[top++] = i;
    }

    cout << area << '\n';
}   