//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        int prod=a*b;
        int gcd=0;
        while(a>0 && b>0){
            if(a<b){
                b=b%a;
            }else{
                a=a%b;
            }
            
            if(a==0) gcd=b;
            else gcd=a;
        }
        
        int lcm=prod/gcd;
        return vector<int>{lcm,gcd};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends