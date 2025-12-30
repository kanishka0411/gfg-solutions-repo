/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool symmetric(Node *left,Node *right){
        if(left==nullptr || right==nullptr) return left==right;
        if(left->data != right->data) return false;
        
        return symmetric(left->left,right->right) && symmetric(left->right,right->left);
    }
    bool isSymmetric(Node* root) {
        return root==nullptr || symmetric(root->left,root->right);
        
    }
};