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
    int log_ = 30; // log(1e9) ~= 29.90
    int up[log_][n+1];
    fill(&up[0][0], &up[0][0] +(n+1)*(log_), -1);

    for (i = 1; i <= n; i++) cin >> up[0][i];
    
    vector<int> skipped(n+1, 0);
    for (j = 1; j < log_; j++) {
        for (i = 1; i <= n; i++) {
            up[j][i] = up[j-1][ up[j-1][i] ];
        }
    }

    while (q--) {
        cin >> target >> jmp;

        for (k = 0; k < log_; k++) {
            // kth bit is 1 (power of 2 is there) // bit decomp
            if ((jmp>>k)&1) target = up[k][target];
        }

        cout << target << '\n';
    }

}