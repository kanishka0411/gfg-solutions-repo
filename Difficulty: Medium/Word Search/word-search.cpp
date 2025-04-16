//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool func(vector<vector<char>>&mat,string &word,int i,int j,int ind){
        if(ind==word.size()){
            return true;
        }
        
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]!=word[ind]){
            return false;
        }
        bool ans=false;
        char x=mat[i][j];
        mat[i][j]=' ';
        
        ans|=func(mat,word,i+1,j,ind+1);
        ans|=func(mat,word,i-1,j,ind+1);
        ans|= func(mat,word,i,j+1,ind+1);
        ans|=func(mat,word,i,j-1,ind+1);
        
        mat[i][j]=x;
        
        return ans;
        
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                    if(func(mat,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends