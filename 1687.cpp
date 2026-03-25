#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
 
int n,q,a,i,j,target,jmp,height,k;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> q;
 
    // binary lifting
    int log_ = (int)log2(n)+1;
    int up[log_][n+1];
 
    up[0][1] = -1;
    for (i = 2; i <= n; i++) cin >> up[0][i];
    
    for (j = 1; j < log_; j++) {
        for (i = 1; i <= n; i++) {
            if (up[j-1][i] != -1) {
                up[j][i] = up[j-1][ up[j-1][i] ];
            }
            else up[j][i] = -1;
        }
    }
 
    while (q--) {
        cin >> target >> jmp;
 
        for (k = 0; k < log_; k++) {
            // kth bit is 1 (power of 2 is there) // bit decomp
            if ((jmp>>k)&1) target = up[k][target];

            if (target == -1) break;
        }

 
        cout << target << '\n';
    }
}