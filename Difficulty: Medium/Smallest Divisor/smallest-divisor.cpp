//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    int func(vector<int>&arr,int x){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)(arr[i])/(double)(x));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        
        //-----------------------------Brute-----------------------------------------
        // int maxi=*max_element(arr.begin(),arr.end());
        // int ans=0;
        // for(int i=1;i<=maxi;i++){
        //     int val=func(arr,i);
        //     if(val<=k){
        //         ans=i;
        //         break;
        //     }
        // }
        // return ans;
        
        //-------------------------------Optimal------------------------------------
        int n=arr.size();
        int low=1;
        int high=*max_element(arr.begin(),arr.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            int val=func(arr,mid);
            if(val<=k){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
    
        
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.smallestDivisor(arr, d);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends