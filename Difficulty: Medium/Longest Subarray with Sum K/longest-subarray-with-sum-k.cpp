//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        int maxLen=0;
        int preSum=0;
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            preSum+=arr[i];
            int req=preSum-k;
            if(mpp.find(req)!=mpp.end()){
                int len=i-mpp[req];
                maxLen=max(maxLen,len);
            }
            if(mpp.find(preSum)==mpp.end()){
                mpp[preSum]=i;
            }
            
        }
        return maxLen;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends