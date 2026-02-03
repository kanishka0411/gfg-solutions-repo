/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        int curr=root->data;
        if(curr<n1->data && curr<n2->data) return LCA(root->right,n1,n2);
        if(curr>n1->data && curr>n2->data) return LCA(root->left,n1,n2);
        return root;
        
    }
};