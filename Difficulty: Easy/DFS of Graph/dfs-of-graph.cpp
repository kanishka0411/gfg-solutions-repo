class Solution {
  public:
    void d(vector<vector<int>>&adj,int start,vector<int>&ans,vector<int>&vis){
        vis[start]=1;
        ans.push_back(start);
        for(auto it:adj[start]){
            if(!vis[it]){
                d(adj,it,ans,vis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int>vis(v,0);
        int start=0;
        vector<int>ans;
        d(adj,start,ans,vis);
        return ans;
        
    }
};