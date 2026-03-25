#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> ans;

typedef struct Node {
    int val;
    vector<struct Node*> children; 
} Node;

Node *createNode(int val) {
    static Node *pool = new Node[n];
    Node *node = &pool[val-1];
    node->val = val;

    return node;
}

int recur(Node *root) {
    if (!root) return 0;

    int size = 1;
    for (Node *child : root->children) size += recur(child);

    return ans[root->val-1] = size;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n;
    ans.resize(n);

    Node **tree = new Node*[n];
    for (int i = 0; i < n; i++) tree[i] = createNode(i+1);
    
    int idx;
    for (int i = 1; i < n; i++) {
        cin >> idx;

        tree[idx-1]->children.push_back(tree[i]);
    }

    recur(tree[0]);
    for (auto x : ans) cout << x-1 << ' ';
    cout << '\n';
}