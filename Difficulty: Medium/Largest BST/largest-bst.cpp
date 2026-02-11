/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    struct Nodevalue{
        int minNode,maxNode,maxSize;
        Nodevalue(int minNode,int maxNode,int maxSize):minNode(minNode),maxNode(maxNode),maxSize(maxSize){}
    };
    
    Nodevalue largestbst(Node *root){
        if(!root) return Nodevalue(INT_MAX,INT_MIN,0);
        
        Nodevalue left=largestbst(root->left);
        Nodevalue right=largestbst(root->right);
        
        if(left.maxNode<root->data && root->data<right.minNode){
            return Nodevalue(
                min(root->data,left.minNode),
                max(root->data,right.maxNode),
                left.maxSize+right.maxSize+1
            );
        }
        
        return Nodevalue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }
    int largestBst(Node *root) {
        return largestbst(root).maxSize;
        
    }
};