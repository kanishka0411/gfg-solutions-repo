/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
            mpp[line]=node->data;
            if(node->left!=nullptr){
                q.push({node->left,line-1});
            }
            if(node->right!=nullptr){
                q.push({node->right,line+1});
            }
        }
        
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};