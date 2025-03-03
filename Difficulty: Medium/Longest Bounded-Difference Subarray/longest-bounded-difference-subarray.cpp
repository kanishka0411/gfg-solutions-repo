//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
      int n = arr.size();
      int i = 0, j = 0;
      int bestStart = 0, maxLen = 0;
    
      multiset<int> window;  // Stores elements in the current window

      while (j < n) {
          window.insert(arr[j]);

        // If the condition is violated, move `i` to restore validity
          while (*window.rbegin() - *window.begin() > x) {
            window.erase(window.find(arr[i]));
            i++;
          }

        // Update longest valid subarray if needed
          if (j - i + 1 > maxLen) {
            maxLen = j - i + 1;
            bestStart = i;
          }

          j++;  // Expand the window
      }

    
      return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLen);
        
        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends