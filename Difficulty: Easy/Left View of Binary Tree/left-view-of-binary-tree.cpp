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
    vector<vector<int>>levelTraversal(Node *root){
 
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<Node*>q;
        q.push({root});
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                Node *top=q.front();
                level.push_back(top->data);
                q.pop();
                
                if(top->left){
                    q.push(top->left);
                }
                
                if(top->right){
                    q.push(top->right);
                }
                
            }
            ans.push_back(level);
        }
    }
    vector<int> leftView(Node *root) {
       vector<vector<int>>left=levelTraversal(root);
       vector<int>ans;
       for(auto level:left){
           ans.push_back(level.front());
       }
       return ans;
        
    }
};