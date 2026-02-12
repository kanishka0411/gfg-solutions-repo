/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void build(Node *root,vector<int>&ans,int &i){
      if(!root) return;
      
      build(root->left,ans,i);
      root->data=ans[i++];
      build(root->right,ans,i);
  }
    void inorder(Node *root,vector<int>&ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    void correctBST(Node* root) {
        vector<int>ans;
        inorder(root,ans);
        sort(ans.begin(),ans.end());
        int i=0;
        build(root,ans,i);
    }
};