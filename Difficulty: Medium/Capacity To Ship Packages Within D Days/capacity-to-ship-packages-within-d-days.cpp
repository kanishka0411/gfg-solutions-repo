//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
    int canLoad(int arr[],int load,int n){
        int maxLoad=0;
        int days=1;
        for(int i=0;i<n;i++){
            if(maxLoad+arr[i]<=load){
                maxLoad+=arr[i];
            }else{
                days++;
                maxLoad=arr[i];
            }
        }
        return days;
    }
    int leastWeightCapacity(int arr[], int n, int d) {
        int maxi=*max_element(arr,arr+n);
        int sum=accumulate(arr,arr+n,0);
        
        //---------------------------------Brute-------------------------------
        // for(int i=maxi;i<=sum;i++){
        //     if(canLoad(arr,i,n)<=d){
        //         return i;
        //     }
        // }
        // return -1;
        
        //----------------------------------Optimal------------------------------
        int low=maxi;
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(canLoad(arr,mid,n)>d){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends