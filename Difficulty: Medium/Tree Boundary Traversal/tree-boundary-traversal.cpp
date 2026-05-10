/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node *root){
        return !root->left && !root->right;
    }
    void addLeftBoundary(Node *root,vector<int>&res){
        Node *left=root->left;
        while(left){
            if(!isLeaf(left)){
                res.push_back(left->data);
            }
            if(left->left) left=left->left;
            else left=left->right;
        }
    }
    void addLeaves(Node *root,vector<int>&res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        
        if(root->left){
            addLeaves(root->left,res);
        }
        if(root->right){
            addLeaves(root->right,res);
        }
    }
    void addRightBoundary(Node *root,vector<int>&res){
        Node *right=root->right;
        vector<int>temp;
        while(right){
            if(!isLeaf(right)){
                temp.push_back(right->data);
            }
            if(right->right) right=right->right;
            else right=right->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
        
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root,res);
        addLeaves(root,res);
        addRightBoundary(root,res);
        return res;
        
    }
};