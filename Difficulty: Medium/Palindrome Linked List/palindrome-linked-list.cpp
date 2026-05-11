/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    Node *reverse(Node *head){
        if(head==nullptr || head->next==nullptr) return head;
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
    bool isPalindrome(Node *head) {
        Node *slow=head;
        Node *fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        Node *secHalf=reverse(slow);
        Node *fir=head;
        Node *sec=secHalf;
        
        while(sec){
            if(fir->data!=sec->data){
                reverse(sec);
                return false;
            }
            fir=fir->next;
            sec=sec->next;
        }
        
        reverse(sec);
        return true;
    }
};