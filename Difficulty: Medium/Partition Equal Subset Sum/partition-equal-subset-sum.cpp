//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%2!=0) return false;
        sum/=2;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
        for(int i=0;i<=n;i++){
            for(int s=0;s<=sum;s++){
                if(i==0) dp[i][s]=false;
                else if(s==0) dp[i][s]=true;
                else if(arr[i-1]<=s){
                    dp[i][s]=dp[i-1][s-arr[i-1]] || dp[i-1][s];
                }else{
                    dp[i][s]=dp[i-1][s];
                }
            }
        }
        return dp[n][sum];
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
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends