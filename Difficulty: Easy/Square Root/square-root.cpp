//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        int st=1;
        int end=n;
        while(st<=end){
            long long mid=st+(end-st)/2;
            long long val=mid*mid;
            if(val<=n){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return end;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends