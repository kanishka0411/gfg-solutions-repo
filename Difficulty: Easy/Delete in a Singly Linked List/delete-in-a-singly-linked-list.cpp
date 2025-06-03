/* Link list Node
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
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        if(head==NULL){
            return NULL;
        }
        if(x==1){
            Node *temp=head;
            head=head->next;
            delete(temp);
            return head;
        }
        
        Node *temp=head;
        Node *prev=nullptr;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            if(cnt==x){
                prev->next=temp->next;
                delete(temp);
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
        
    }
};