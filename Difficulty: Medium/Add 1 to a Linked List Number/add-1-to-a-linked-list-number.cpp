/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
   Node *reverse(Node *head){
       Node *temp=head;
       Node *prev=nullptr;
       while(temp!=nullptr){
           Node *front=temp->next;
           temp->next=prev;
           prev=temp;
           temp=front;
       }
       return prev;
   }
    Node* addOne(Node* head) {
       head=reverse(head);
       Node *curr=head;
       int carry=1;
       while(curr!=nullptr){
           int sum=curr->data+1;
           carry=sum/10;
           curr->data=sum%10;
           if(carry==0) break;
           if(curr->next==nullptr && carry!=0){
               curr->next=new Node(carry);
               break;
           }
           curr=curr->next;
           
       }
       head=reverse(head);
       return head;
        
    }
};