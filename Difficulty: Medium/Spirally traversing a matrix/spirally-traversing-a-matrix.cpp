//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int>res;
        int n=mat.size();
        int m=mat[0].size();
        int srow=0,erow=n-1;
        int scol=0,ecol=m-1;
        while(srow<=erow && scol<=ecol){
            for(int j=scol;j<=ecol;j++){
                res.push_back(mat[srow][j]);
            }
            for(int i=srow+1;i<=erow;i++){
                res.push_back(mat[i][ecol]);
            }
            for(int j=ecol-1;j>=scol;j--){
                if(srow==erow){
                    break;
                }
                res.push_back(mat[erow][j]);
            }
            for(int i=erow-1;i>=srow+1;i--){
                if(scol==ecol){
                    break;
                }
                res.push_back(mat[i][scol]);
                
            }
            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return res;
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends