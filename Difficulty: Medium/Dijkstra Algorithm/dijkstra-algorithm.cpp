class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //build the adjancy list first
       vector<vector<pair<int,int>>>adj(V);
       int n=edges.size();
       for(int i=0;i<n;i++){
           int u=edges[i][0];
           int v=edges[i][1];
           int w=edges[i][2];
           
           adj[u].push_back({v,w});
           adj[v].push_back({u,w});
       }
       
       set<pair<int,int>>st;
       st.insert({0,src});
       vector<int>dist(V,1e9);
       dist[src]=0;
       
      while(!st.empty()){
          auto it=*(st.begin());
          int distance=it.first;
          int node=it.second;
          st.erase(it);
          
          for(auto it:adj[node]){
              int adjNode=it.first;
              int egW=it.second;
              if(distance+egW<dist[adjNode]){
                  if(dist[adjNode]!=1e9){
                      st.erase({dist[adjNode],adjNode});
                  }
                  dist[adjNode]=distance+egW;
                  st.insert({dist[adjNode],adjNode});
              }
          }
      }
      return dist;
        
    }
};