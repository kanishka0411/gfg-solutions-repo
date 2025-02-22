//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   
    bool getSubsetSum(vector<int>&arr,int n,int target,vector<vector<int>>&t){
        
        if(target==0){
            return true;
        }
        if(n==0){
            return false;
        }
        
        if(t[n][target]!=-1){
            return t[n][target];
        }
        
        if(target<arr[n-1]){
            return t[n][target]= getSubsetSum(arr,n-1,target,t);
        }
            return t[n][target]=getSubsetSum(arr,n-1,target-arr[n-1],t) || getSubsetSum(arr,n-1,target,t);
        
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>t(n+1,vector<int>(target+1,-1));
        return getSubsetSum(arr,n,target,t);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends