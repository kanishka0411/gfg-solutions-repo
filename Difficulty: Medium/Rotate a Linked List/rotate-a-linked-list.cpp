//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
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
    Node* rotate(Node* head, int k) {
         if (k == 0 || head == nullptr)
        return head;

    Node *curr = head;
    int len = 1;
  
      // Find the length of linked list
    while (curr->next != nullptr) {
        curr = curr->next;
        len += 1;
    }

      // Modulo k with length of linked list to handle
      // large values of k
    k %= len;
  
    if (k == 0)
        return head;
  
      // Make the linked list circular
    curr->next = head;

      // Traverse the linked list to find the kth node
    curr = head;
    for (int i = 1; i < k; i++)
        curr = curr->next;

      // Update the (k + 1)th node as the new head
    head = curr->next;
  
      // Break the loop by updating next pointer of kth node
    curr->next = nullptr;
    return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends