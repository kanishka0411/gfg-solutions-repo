/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node *fast=head;
        Node *slow=head;
        int cnt=1;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                Node*temp=slow->next;
                while(temp!=slow){
                    cnt++;
                    temp=temp->next;
                }
                return cnt;
            }
        }
        return 0;
        
        
    }
};