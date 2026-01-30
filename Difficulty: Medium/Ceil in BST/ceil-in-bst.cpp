class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceil=-1;
        while(root!=nullptr){
            if(root->data==x){
                ceil=root->data;
                break;
            }
            if(root->data>x){
                ceil=root->data;
                root=root->left;
            }
            else root=root->right;
        }
        return ceil;
        
        
    }
};
