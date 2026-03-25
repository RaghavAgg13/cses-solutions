#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[200001];
bool done[200001];
int count;

void recur(int root, int parent) {
    for (int child : adj[root]) {
        if (child != parent) {
            recur(child, root);
            
            if (!done[child] && !done[root]) {
                done[child] = done[root] = true;
                count++;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n;
    cin >> n;

    int a,b;
    while (--n) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    count = 0;
    recur(1, 0);

    cout << count << '\n';
}