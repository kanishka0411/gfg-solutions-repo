//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int count(vector<int>&arr,int n,int target,vector<vector<int>>&t){
        if(n==0) return (target==0)?1:0;
        // if(target==0) return 1;
        if(t[n][target]!=-1) return t[n][target];
        if(arr[n-1]>target){
            return t[n][target]=count(arr,n-1,target,t);
        }
        return t[n][target]=count(arr,n-1,target-arr[n-1],t)+count(arr,n-1,target,t);
    }
    
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>t(n+1,vector<int>(target+1,-1));
        return count(arr,n,target,t);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends