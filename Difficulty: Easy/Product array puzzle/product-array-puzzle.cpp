//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        vector<int>ans;
        int n=arr.size();
        int prod=1;
        int count0=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                count0++;
            }else{
                prod*=arr[i];
            }
        }

        for(int i=0;i<n;i++){
            if(count0>1){
                ans.push_back(0);
            }else if(count0==1){
                if(arr[i]==0){
                    ans.push_back(prod);
                }else{
                    ans.push_back(0);
                }
            }else{
                ans.push_back(prod/arr[i]);
            }
        }
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends