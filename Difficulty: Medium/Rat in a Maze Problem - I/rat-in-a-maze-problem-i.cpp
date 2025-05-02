//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    void func(vector<vector<int>>&maze,set<string>&ans,string s,int x,int y,int n){
        if(x==n-1 && y==n-1){
            ans.insert(s);
            return;
        }
        if(x>=n || y>=n || x<0 || y<0 || maze[x][y]==0 || maze[x][y]==-1){
            return;
        }
        int z=maze[x][y];
        maze[x][y]=-1;
        func(maze,ans,s+'D',x+1,y,n);
        func(maze,ans,s+'U',x-1,y,n);
        func(maze,ans,s+'R',x,y+1,n);
        func(maze,ans,s+'L',x,y-1,n);
        maze[x][y]=z;
        
    }
   
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n=maze.size();
        set<string>ans;
        string s;
        func(maze,ans,s,0,0,n);
        return vector<string>(ans.begin(),ans.end());
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        vector<string> result = obj.ratInMaze(mat);
        // sort(result.begin(), result.end());

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