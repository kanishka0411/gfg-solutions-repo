/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
    Node* deleteMid(Node* head) {
       if(head==nullptr || head->next==nullptr) return nullptr;
       Node *slowp=head;
       Node *fastp=head;
       Node *prev=nullptr;
       while(fastp!=nullptr && fastp->next!=nullptr){
           prev=slowp;
           slowp=slowp->next;
           fastp=fastp->next->next;
       }
       prev->next=slowp->next;
       delete(slowp);
       return head;
    }
};