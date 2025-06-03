/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int len=0;
        Node *temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
        
    }
};