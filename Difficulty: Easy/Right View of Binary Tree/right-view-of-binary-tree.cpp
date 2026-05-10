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
    void levelOrder(Node *root,vector<vector<int>>&ans){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node *curr=q.front();
                q.pop();
                level.push_back(curr->data);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans.push_back(level);
        }
    }
    vector<int> rightView(Node *root) {
        vector<vector<int>>ans;
        levelOrder(root,ans);
        vector<int>res;
        for(auto it:ans){
            res.push_back(it.back());
        }
        return res;
        
        
    }
};