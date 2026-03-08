#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node* buildTree() {
    cout << "Nhập giá trị nút gốc (-1 nếu rỗng): ";
    int val;
    cin >> val;

    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        cout << "Nhập giá trị con trái của " << curr->data << " (-1 nếu rỗng): ";
        int leftVal;
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Nhập giá trị con phải của " << curr->data << " (-1 nếu rỗng): ";
        int rightVal;
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}
