//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        int st=1;
        int end=m;
        while(st<=end){
            int mid=st+(end-st)/2;
            int power=1;
            for(int i=1;i<=n;i++){
                power*=mid;
                if(power>m){
                    break;
                }
            }
            
            if(power==m){
                return mid;
            }
            if(power>m){
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