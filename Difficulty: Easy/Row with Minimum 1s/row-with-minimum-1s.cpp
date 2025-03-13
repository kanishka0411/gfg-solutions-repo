//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
  
   
    
    int minRow(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=1;
        int mini=INT_MAX;;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            
            if(cnt<mini){
                mini=cnt;
                ans=i;
            }
        }
        return ans+1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> mat(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(mat) << "\n";
        cout << "~\n";
    }
}
// } Driver Code Ends