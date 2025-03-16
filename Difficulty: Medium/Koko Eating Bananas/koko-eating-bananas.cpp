//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int calc(vector<int>&arr,int x){
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)(arr[i])/(x));
        }
        return sum;
    }
    int kokoEat(vector<int>& arr, int k) {
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        
        //-------------------------------Brute-----------------------------------
        // for(int i=1;i<=maxi;i++){
        //     int noOfBananas=calc(arr,i);
        //     if(noOfBananas==k) return i;
        // }
        
        //-------------------------------Optimal---------------------------------
        
        int low=1;
        int high=maxi;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(calc(arr,mid)<=k){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;

        cout << ob.kokoEat(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends