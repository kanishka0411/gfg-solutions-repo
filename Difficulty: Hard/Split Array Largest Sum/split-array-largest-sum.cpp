//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int split(int arr[],int mid,int n){

        int splitArray=1;
        int splitCount=0;
        for(int i=0;i<n;i++){
            if(splitCount+arr[i]<=mid){
                splitCount+=arr[i];
            }else{
                splitArray++;
                splitCount=arr[i];
            }
        }
        return splitArray;
    }
    int splitArray(int arr[] ,int N, int K) {
        int low=*max_element(arr,arr+N);
        int high=accumulate(arr,arr+N,0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(split(arr,mid,N)>K){
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends