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
    vector<int> inOrder(Node* root) {
        vector<int>inorder;
        Node *curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                inorder.push_back(curr->data);
                curr=curr->right;
            }else{
                Node *left=curr->left;
                while(left->right!=nullptr){
                    left=left->right;
                }
                left->right=curr;
                Node*temp=curr;
                curr=curr->left;
                temp->left=nullptr;
            }
        }
        return inorder;
        
    }
};