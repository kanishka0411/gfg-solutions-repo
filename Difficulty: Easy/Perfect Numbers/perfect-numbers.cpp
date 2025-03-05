//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPerfectNumber(int n) {
        int num=n;
        int sum=1;
        for(int i=2;i*i<=n;i++){
            if(num%i==0){
                if(i*i!=n) sum+=i+num/i;
                else sum+=i;
            }
        }
        return sum==n || n==1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin >> N;

        Solution ob;
        bool ans = ob.isPerfectNumber(N);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends