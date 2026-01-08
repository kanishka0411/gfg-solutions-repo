/*  Structure of a Binary Tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    int maxWidth(Node* root) {
        if(!root) return 0;
        int ans=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            ans=max(ans,size);
            
            for(int i=0;i<size;i++){
                Node *curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            
        }
        
        return ans;
        
        
    }
};