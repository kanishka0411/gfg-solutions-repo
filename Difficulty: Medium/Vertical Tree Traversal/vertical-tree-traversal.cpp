/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        map<int,map<int,vector<int>>>nodes;
        queue<pair<Node*,pair<int,int>>>todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            Node *curr=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].push_back(curr->data);
            if(curr->left){
                todo.push({curr->left,{x-1,y+1}});
            }
            if(curr->right){
                todo.push({curr->right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};