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
        vector<Node*>ans;
        Node *pre=nullptr;
        Node *succ=nullptr;
        Node *node=root;
        while(node){
            if(node->data<=key){
                node=node->right;
            }else{
                pre=node;
                node=node->left;
            }
        }
        node=root;
        while(node){
            if(node->data>=key){
                node=node->left;
            }else{
                succ=node;
                node=node->right;
            }
        }
        ans.push_back(succ);
        ans.push_back(pre);
        return ans;
        
        
        
    }
};