/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node *fast=head;
        Node *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                int cnt=1;
                fast=fast->next;
                while(fast!=slow){
                    fast=fast->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
        
    }
};