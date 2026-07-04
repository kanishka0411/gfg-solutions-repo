class Solution {
  public:
    void d(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&ls){
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                d(it,adj,vis,ls);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>vis(n,0);
        int start=0;
        vector<int>ls;
        d(start,adj,vis,ls);
        return ls;
        
    }
};