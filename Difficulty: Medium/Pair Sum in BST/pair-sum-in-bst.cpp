/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class BSTIterator{
    stack<Node*>st;
    bool reverse;
    public:
        BSTIterator(Node *root,bool rev){
            
            reverse=rev;
            pushAll(root);
        }
        bool hasnext(){
            return !st.empty();
        }
        
        int next(){
            Node*node=st.top();
            st.pop();
            if(reverse) pushAll(node->left);
            else pushAll(node->right);
            return node->data;
        }
        
        void pushAll(Node *node){
            while(node){
                st.push(node);
                if(reverse) node=node->right;
                else  node=node->left;
            }
        }
};

class Solution {
  public:
  
    bool findTarget(Node *root, int target) {
        if(!root) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        if(!l.hasnext() || !r.hasnext()) return false;
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==target) return true;
            if(i+j<target) i=l.next();
            else j=r.next();
        }
        return false;
    }
};