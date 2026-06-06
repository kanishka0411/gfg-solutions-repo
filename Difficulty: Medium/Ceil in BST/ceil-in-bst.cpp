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
    int findCeil(Node* root, int x) {
        int ceil=-1;
        Node *curr=root;
        while(curr!=nullptr){
            if(curr->data==x){
                ceil=curr->data;
                break;
            }
            if(curr->data>x){
                ceil=curr->data;
                curr=curr->left;
            }else{
                curr=curr->right;
            }
        }
        return ceil;
    }
};
