/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        Node *temp=head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->data==temp->next->data){
                Node *delNode=temp->next;
                Node *nextNode=temp->next->next;
                temp->next=nextNode;
                if(nextNode){
                    nextNode->prev=temp;
                }
                delNode->prev=nullptr;
                delNode->next=nullptr;
                delete(delNode);
            }else{
                temp=temp->next;
            }
        }
        return head;
        
    }
};