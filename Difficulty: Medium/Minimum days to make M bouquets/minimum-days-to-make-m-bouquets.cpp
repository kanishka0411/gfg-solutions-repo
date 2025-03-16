//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPossible(vector<int>&arr,int day,int m,int k){
        int n=arr.size();
        int cnt=0;
        int noOfB=0;
        for(int i=0;i<n;i++){
            if(arr[i]<=day) cnt++;
            else{
                noOfB+=cnt/k;
                cnt=0;
            }
        }
        noOfB+=cnt/k;
        return noOfB>=m;
    }
    int minDaysBloom(int m, int k, vector<int> &arr) {
        int n=arr.size();
        int mini=*min_element(arr.begin(),arr.end());
        int maxi=*max_element(arr.begin(),arr.end());
        
        //---------------------------------Brute-----------------------------------
        // for(int i=mini;i<=maxi;i++){
        //     if(isPossible(arr,i,m,k)){
        //         return i;
        //     }
        // }
        // return -1;
        
        //----------------------------------Optimal--------------------------------
        int val=m*k;
        if(val>n) return -1;
        int low=mini;
        int high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;;
            if(isPossible(arr,mid,m,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        getline(cin, str);
        int m = stoi(str);
        getline(cin, str);
        int k = stoi(str);
        Solution obj;
        cout << obj.minDaysBloom(m, k, arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends