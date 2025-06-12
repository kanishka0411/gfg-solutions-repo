/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *merge(Node *list1,Node *list2){
        Node *dummy=new Node(-1);
        Node *res=dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->data<list2->data){
                res->bottom=list1;
                res=list1;
                list1=list1->bottom;
            }else{
                res->bottom=list2;
                res=list2;
                list2=list2->bottom;
            }
        }
        if(list1) res->bottom=list1;
        else res->bottom=list2;
        
        if(dummy->bottom) dummy->bottom->next=nullptr;
        return dummy->bottom;
    }
    Node *flatten(Node *root) {
        if(root==nullptr ||root->next==nullptr) return root;
        Node *mergedhead=flatten(root->next);
        root=merge(root,mergedhead);
        return root;
        
    }
};