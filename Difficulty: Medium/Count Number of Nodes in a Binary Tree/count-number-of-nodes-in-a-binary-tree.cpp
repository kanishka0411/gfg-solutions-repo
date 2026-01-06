// User function Template for C++

class Solution {
  public:
    void rec(Node *root,int &cnt){
        if(root==nullptr) return;
        cnt++;
        rec(root->left,cnt);
        rec(root->right,cnt);
    }
    int countNodes(Node* root) {
       if(root==nullptr) return 0;
       int cnt=0;
       rec(root,cnt);
       return cnt;
        
    }
};