/*
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        if (head==nullptr) return new Node(x);
        Node *curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        Node *newNode=new Node(x);
        curr->next=newNode;
        return head;
    }
};