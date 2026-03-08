#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
       int data;
       Node *left;
       Node *right;

       Node(int x){
        data=x;
        left = right = nullptr;
       }
};

int maxSumPath(Node*node, unordered_map<Node*,int>&memo){
    if(node==nullptr){
        return 0;
    }

    if(memo.find(node)!=memo.end()){
        return memo[node];
    }

    if(node->left==nullptr && node->right==nullptr){
        return memo[node]=node->data;
    }

    int leftSum=maxSumPath(node->left,memo);
    int rightSum=maxSumPath(node->right,memo);
    memo[node] = node->data + max(leftSum, rightSum);
    return memo[node];
}

int maxRootToLeafSum(Node*root){
    unordered_map<Node*, int> memo;
    return maxSumPath(root, memo);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << maxRootToLeafSum(root) << endl;

    return 0;
}
