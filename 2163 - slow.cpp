#include <iostream>
using namespace std;
#define ll long long

ll n,k;

typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int val) {
    Node *node = new Node;
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> k;
    Node *head = new Node;
    Node *cur = head;

    for (int i = 0; i < n; i++) {
        head->next = createNode(i+1);
        head->next->prev = head;
        head = head->next;
    }
    cur = cur->next;
    head->next = cur;
    cur->prev = head;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        ll step = k%(n-cnt);
        for (int j = 0; j < step; j++) cur = cur->next;

        Node *prev = cur->prev, *next = cur->next;
        prev->next = next;
        next->prev = prev;
        cout << cur->val << ' ';
        
        cnt++;
        
        cur = next;
    }
}