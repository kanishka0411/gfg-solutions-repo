class Solution {
  public:
    int findCeil(Node* root, int x) {
        Node *curr=root;
        int ceil=-1;
        while(curr){
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
