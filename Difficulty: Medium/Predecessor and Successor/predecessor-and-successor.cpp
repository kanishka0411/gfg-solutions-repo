/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    vector<Node*> findPreSuc(Node* root, int key) {
        Node *pre=nullptr;
        Node *succ=nullptr;
        Node *node=root;
        while(node){
            if(node->data>=key){
                node=node->left;
            }else{
                pre=node;
                node=node->right;
            }
            
        }
        node=root;
        while(node){
            if(node->data<=key){
                node=node->right;
            }else{
                succ=node;
                node=node->left;
            }
        }
        
        return {pre,succ};
        
    }
};