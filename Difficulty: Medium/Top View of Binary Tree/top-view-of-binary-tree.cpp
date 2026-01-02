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
    vector<int> topView(Node *root) {
       queue<pair<Node*,int>>q;
       map<int,int>mpp;
       q.push({root,0});
       while(!q.empty()){
           auto it=q.front();
           q.pop();
           Node *curr=it.first;
           int line=it.second;
           if(mpp.find(line)==mpp.end()){
               mpp[line]=curr->data;
           }
           
           if(curr->left){
               q.push({curr->left,line-1});
           }
           if(curr->right){
               q.push({curr->right,line+1});
           }
       }
       vector<int>ans;
       for(auto it:mpp){
           ans.push_back(it.second);
       }
       return ans;
        
    }
};