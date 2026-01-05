/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        queue<pair<Node *,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node *curr=it.first;
            int x=it.second;
            mpp[x]=curr->data;
            
            if(curr->left){
                q.push({curr->left,x-1});
            }
            if(curr->right){
                q.push({curr->right,x+1});
            }
        }
        
        vector<int>ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};