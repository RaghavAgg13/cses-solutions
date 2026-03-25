#include <iostream>
#include <vector>
using namespace std;
 
int n,top,a;
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    vector<int> arr(n), Q(n);
    for (auto &x : arr) cin >> x;

    top = 0;
    for (int i = 0; i < n; i++) {
        while (top && arr[Q[top-1]] >= arr[i]) top--;
        
        if (top == 0) cout << "0 ";
        else cout << Q[top-1]+1 << " ";

        Q[top++] = i;
    }
}   