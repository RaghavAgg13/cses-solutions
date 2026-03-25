#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
 
int t,n;
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    string a;
    cin >> a;
    n = a.length();

    vector<int> freq(26);
    for (auto x : a) freq[x-'A']++;

    string res = "";
    int last = -1;

    for (int i = 0; i < n; i++) {
        int best_char = -1;
        int remaining_len = n-i;

        int max_f = 0;
        for (int k = 0; k < 26; k++) max_f = max(max_f, freq[k]);

        // get best character
        if (2*max_f > remaining_len) {
            for (int k = 0; k < 26; k++) {
                if (freq[k] == max_f && k != last) {
                    best_char = k;
                    break;
                }
            }
        } else {
            for (int k = 0; k < 26; k++) {
                if (freq[k] && k != last) {
                    best_char = k;
                    break;
                }
            }
        }
        
        
        if (best_char == -1) {
            cout << "-1\n";
            return 0;
        }

        res += (char)(best_char+'A');
        freq[best_char]--;
        last = best_char;
    }
    cout << res << endl;
}