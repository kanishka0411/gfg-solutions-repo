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
    int dfs(Node *root,int &maxi){
        if(root==nullptr) return 0;
        int lh=dfs(root->left,maxi);
        int rh=dfs(root->right,maxi);
        
        maxi=max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
    int diameter(Node* root) {
        int maxi=0;
        dfs(root,maxi);
        return maxi;
        
    }
};