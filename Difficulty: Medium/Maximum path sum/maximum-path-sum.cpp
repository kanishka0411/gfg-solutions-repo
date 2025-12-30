/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int dfs(Node *root,int &sum){
        if(root==nullptr) return 0;
        int lh=max(0,dfs(root->left,sum));
        int rh=max(0,dfs(root->right,sum));
        
        sum=max(sum,lh+rh+root->data);
        return max(lh,rh)+root->data;
    }
    int findMaxSum(Node *root) {
        int sum=INT_MIN;
        dfs(root,sum);
        return sum;
        
    }
};