class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) { 
        int v=adj.size();
        vector<int>vis(v,0);
        vis[0]=1;
        vector<int>ans;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                if(vis[it]!=1){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return ans;
        
    }
};