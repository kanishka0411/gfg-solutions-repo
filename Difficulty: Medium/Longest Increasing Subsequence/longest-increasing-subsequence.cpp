//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[1001][1001];
    int n;
    int lis(vector<int>& arr) {
        //we will use take and skip approach to solve use 
        //recursion+memoization 
        n=arr.size();
        memset(dp,-1,sizeof(dp));//setting vals as -1 can use for loop also
        return solve(arr,0,-1);
    }

    int solve(vector<int>&arr,int idx,int prev){
        if(idx>=n) return 0; //bounds check 

        if(prev!=-1 && dp[idx][prev]!=-1) return dp[idx][prev];

        int take=0;
        if(prev==-1 || arr[idx]>arr[prev]){
            take=1+solve(arr,idx+1,idx);
        }

        int skip=solve(arr,idx+1,prev);

        if(prev!=-1) dp[idx][prev]=max(take,skip);

        return max(take,skip);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends