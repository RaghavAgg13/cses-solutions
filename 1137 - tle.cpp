#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll n,q,x,a,b,tr;

typedef struct Node {
    ll val, sum;
    vector<int> children; 
    struct Node *parent;
} Node;

vector<Node*> tree;

Node *createNode(ll val) {
    static Node *pool = new Node[n];
    Node *node = &pool[tr++];

    node->val = val; node->sum = val;
    node->parent = NULL;

    return node;
}

void build(int r, int p) {
    if (r > n) return;

    ll s = 0;
    for (int i = 0; i < tree[r]->children.size(); i++) {
        int x = tree[r]->children[i];

        if (x != p) {
            tree[x]->parent = tree[r];

            for (int j = 0; j < tree[x]->children.size(); ++j) {
                if (tree[x]->children[j] == r) {
                    tree[x]->children[j] = tree[x]->children.back();
                    tree[x]->children.pop_back();
                    break;
                }
            }
            build(x, r);
            s += tree[x]->sum;
        }
    }
    tree[r]->sum += s;
}


void update(int r, Node *t, int val) {
    ll diff = val - t->val;
    t->val = val;

    while (t != NULL) {
        t->sum += diff;
        t = t->parent;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    tr = 0;
    cin >> n >> q;
    tree.resize(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> x;
        tree[i] = createNode(x);
    }

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        tree[a]->children.push_back(b);
        tree[b]->children.push_back(a);
    }

    build(1, -1);

    while (q--) {
        cin >> x;

        if (x == 1) {
            cin >> a >> b;
            update(1, tree[a], b);
        }
        else {
            cin >> a;
            cout << tree[a]->sum << '\n';
        }
    }
}   