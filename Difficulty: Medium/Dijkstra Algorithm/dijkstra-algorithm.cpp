class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //build the adjancy list first
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0]; //start node
            int v=edges[i][1]; //target node
            int weight=edges[i][2];
            
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        
        //===========================
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        st.insert({0,src});
        dist[src]=0;
        
        while(!st.empty()){
            auto it=*(st.begin());
            int distance=it.first;
            int node=it.second;
            st.erase(it);
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edWg=it.second;
                
                if(distance+edWg<dist[adjNode]){
                    //erase if it existed
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    
                    dist[adjNode]=distance+edWg;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
        
    }
};