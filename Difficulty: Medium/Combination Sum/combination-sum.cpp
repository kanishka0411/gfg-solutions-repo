//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    void func(vector<int>&arr,vector<vector<int>>&ans,vector<int>&temp,int target,int i){
        int n=arr.size();
        if(target==0){
            ans.push_back(temp);
            return;
        }
        
        if(target<0 || i>=n){
            return;
        }
        
        temp.push_back(arr[i]);
        func(arr,ans,temp,target-arr[i],i);
        temp.pop_back();
        
        func(arr,ans,temp,target,i+1);
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(arr,ans,temp,target,0);
        return ans;
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
        vector<vector<int>> ans = ob.combinationSum(arr, sum);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            for (int i = 0; i < ans.size(); i++) {
                sort(ans[i].begin(), ans[i].end());
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends