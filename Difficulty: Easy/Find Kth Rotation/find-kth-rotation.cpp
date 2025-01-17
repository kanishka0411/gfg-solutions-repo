//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        int index=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]<=arr[high]){
                if(arr[low]<ans){
                    index=low;
                    ans=arr[low];
                }
                break;
            }
            if(arr[low]<=arr[mid]){
                if(arr[low]<ans){
                    ans=arr[low];
                    index=low;
                }
                low=mid+1;
            }else{
                high=mid-1;
                if(arr[mid]<ans){
                    ans=arr[mid];
                    index=mid;
                }
            }
        }
        return index;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends