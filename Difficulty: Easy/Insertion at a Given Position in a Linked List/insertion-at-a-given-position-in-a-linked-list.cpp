/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
        if(head==nullptr){
            if(pos==1){
                return new Node(val);
            }else{
                return head;
            }
        }
        if(pos==1){
            Node *newNode=new Node(val);
            newNode->next=head;
            return newNode;
        }
        
        int cnt=1;
        Node *curr=head;
        while(curr!=nullptr){
          
            if(cnt==(pos-1)){
                Node *newNode=new Node(val);
                newNode->next=curr->next;
                curr->next=newNode;
                break;
            }
            cnt++;
            curr=curr->next;
        }
        return head;
        
    }
};