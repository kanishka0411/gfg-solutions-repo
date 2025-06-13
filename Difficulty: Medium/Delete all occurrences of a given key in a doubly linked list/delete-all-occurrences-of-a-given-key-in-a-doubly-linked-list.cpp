// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        if(head==nullptr || *head==nullptr) return;
        while(*head && (*head)->data==x){
             Node *delNode=*head;
            *head=(*head)->next;
            if(*head){
                (*head)->prev=nullptr;
            }
            delNode->next=nullptr;
            delete(delNode);
            
        }
        
        Node *temp=*head;
        while(temp!=NULL){
            if(temp->data==x){
                Node *delNode=temp;
                Node *nextNode=temp->next;
                Node *prevNode=temp->prev;
                
                if(nextNode){
                    prevNode->next=nextNode;
                    nextNode->prev=prevNode;
                }else{
                    prevNode->next=nullptr;
                }
                temp=nextNode;
                delNode->prev=nullptr;
                delNode->next=nullptr;
                delete(delNode);
            }else{
                temp=temp->next;
            }
        }
        
        
    }
};