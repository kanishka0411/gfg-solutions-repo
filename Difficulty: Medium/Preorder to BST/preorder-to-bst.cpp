// User function template in C++

/*

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;


// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

*/

class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node *build(int pre[],int &size,int &i,int bound){
        if(i==size || pre[i]>bound) return nullptr;
        Node *node=newNode(pre[i++]);
        node->left=build(pre,size,i,node->data);
        node->right=build(pre,size,i,bound);
        return node;
        
    }
    Node* Bst(int pre[], int size) {
        int i=0;
        return build(pre,size,i,INT_MAX);
    }
};