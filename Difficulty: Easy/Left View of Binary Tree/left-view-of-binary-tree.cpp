/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    void rec(Node* root,int level,vector<int>&res){
        if(root==nullptr) return;
        if(level==res.size()) res.push_back(root->data);
        rec(root->left,level+1,res);
        rec(root->right,level+1,res);
    }
    vector<int> leftView(Node *root) {
       vector<int>res;
       rec(root,0,res);
       return res;
        
    }
};