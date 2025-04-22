//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void func(vector<vector<int>>&mat,vector<string>&ans,int i,int j,string s){
        int n=mat.size();
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        
        if(i<0 || j<0 || i>=n || j>=n || mat[i][j]==0 || mat[i][j]==' '){
            return;
        }
        int x=mat[i][j];
        mat[i][j]=' ';
        func(mat,ans,i+1,j,s+'D');
        func(mat,ans,i-1,j,s+'U');
        func(mat,ans,i,j+1,s+'R');
        func(mat,ans,i,j-1,s+'L');
        mat[i][j]=x;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string>ans;
        string s;
        func(mat,ans,0,0,s);
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends