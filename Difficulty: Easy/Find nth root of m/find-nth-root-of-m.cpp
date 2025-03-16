//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

  
    int func(int x,int n,int m){
        // returns 1 if ==m
        // returns 0 if <m
        // return 2 if >m
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans*=x;
            if(ans>m) return 2;
        }
        if(ans==m) return 1;
        
        return 0;
    }
    int nthRoot(int n, int m) {
        
        //-------------------------------Brute--------------------------------------
    //   for(int i=1;i<=m;i++){
    //       int val=func(i,n);
    //       if(val==m){
    //           return i;
    //       }
    //   }
    //   return -1;
       
       
       //---------------------------------Optimal----------------------------------
       int low=1;
       int high=m;
       while(low<=high){
           int mid=(low+high)/2;
           int midN=func(mid,n,m);
           if(midN==1) return mid;
           else if(midN==2) high=mid-1;
           else low=mid+1;
       }
       return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends