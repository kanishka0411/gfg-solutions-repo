/* A binary tree node


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
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        if(r1 ==nullptr && r2==nullptr) return true;
        if(r1==nullptr || r2==nullptr) return false;
        if(r1->data!=r2->data) return false;
        return isIdentical(r1->left,r2->left) && isIdentical(r1->right ,r2->right);
        
        
    }
};