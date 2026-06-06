/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int floor=-1;
        Node *curr=root;
        while(curr!=nullptr){
            if(curr->data==k){
                floor=curr->data;
                break;
            }
            if(curr->data<k){
                floor=curr->data;
                curr=curr->right;
            }else{
                curr=curr->left;
            }
        }
        return floor;
        
    }
};