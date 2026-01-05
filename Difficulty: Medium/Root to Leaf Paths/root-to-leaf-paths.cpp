/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void rec(Node *root,vector<vector<int>>&ans,vector<int>&temp){
        if(root==nullptr){
            return;
        }
        temp.push_back(root->data);
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(temp);
        }
        
        
        rec(root->left,ans,temp);
        rec(root->right,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>ans;
        vector<int>temp;
        rec(root,ans,temp);
        return ans;
        
    }
};