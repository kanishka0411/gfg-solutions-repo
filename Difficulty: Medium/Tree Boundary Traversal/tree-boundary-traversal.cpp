/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
bool isLeaf(Node *root){
    return !root->left && !root->right;
}

void addLeftBound(Node *root,vector<int>&res){
    Node *curr=root->left;
    while(curr){
        if(!isLeaf(curr)){
        res.push_back(curr->data);
        }
       if(curr->left) curr=curr->left;
       else curr=curr->right;
    }
}

void addLeaves(Node *root,vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left){
        addLeaves(root->left,res);
    }
    if(root->right){
        addLeaves(root->right,res);
    }
    
}

void addRightBound(Node *root,vector<int>&res){
    Node *curr=root->right;
    vector<int>temp;
    while(curr){
        if(!isLeaf(curr)){
        temp.push_back(curr->data);
        }
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}
class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBound(root,res);
        addLeaves(root,res);
        addRightBound(root,res);
        return res;
    }
};