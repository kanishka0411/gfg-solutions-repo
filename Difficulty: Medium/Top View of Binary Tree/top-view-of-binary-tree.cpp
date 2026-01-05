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
       vector<int>ans;
       queue<pair<Node*,int>>q;
       map<int,int>mpp;
       q.push({root,0});
       while(!q.empty()){
           auto it=q.front();
           q.pop();
           Node *curr=it.first;
           int x=it.second;
           if(mpp.find(x)==mpp.end()){
               mpp[x]=curr->data;
           }
           
           if(curr->left){
               q.push({curr->left,x-1});
           }
           if(curr->right){
               q.push({curr->right,x+1});
           }
       }
       
       for(auto it:mpp){
           ans.push_back(it.second);
       }
       
       return ans;
        
    }
};