/*
Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int find(Node *root,int &maxi){
        if(!root) return 0;
        int lh=max(0,find(root->left,maxi));
        int rh=max(0,find(root->right,maxi));
        maxi=max(maxi,lh+rh+root->data);
        return max(lh,rh)+root->data;
    }
    int findMaxSum(Node *root) {
       int maxi=INT_MIN;
       find(root,maxi);
       return maxi;
        
    }
};