//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findOnce(vector<int>& arr) {
        int n=arr.size();
        int st=0;
        int end=n-1;
        if(n==1) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];
        if(arr[0]!=arr[1]) return arr[0];
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
                return arr[mid];
            }
            
            if(mid%2==0 && arr[mid]!=arr[mid+1] || mid%2==1 && arr[mid]!=arr[mid-1]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.findOnce(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends