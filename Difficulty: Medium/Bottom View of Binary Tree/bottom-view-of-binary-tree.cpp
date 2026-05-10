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
    vector<int> bottomView(Node *root) {
        vector<int>res;
        queue<pair<Node*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node *node=it.first;
            int x=it.second;
            mpp[x]=node->data;
            
            if(node->left){
                q.push({node->left,x-1});
            }
            
            if(node->right){
                q.push({node->right,x+1});
            }
        }
        
        for(auto it:mpp){
            res.push_back(it.second);
        }
        return res;
        
    }
};