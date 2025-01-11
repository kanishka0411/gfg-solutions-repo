//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int i=0;
        int j=0;
        int n=s.size();
        int maxlen=1;
        unordered_set<char>st;
        while(j<n){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                j++;
                int currwin=j-i;//as 0 based indexing
                maxlen=max(maxlen,currwin);
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return maxlen;
    
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends