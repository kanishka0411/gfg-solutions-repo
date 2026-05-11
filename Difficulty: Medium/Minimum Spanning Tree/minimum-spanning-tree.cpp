class Solution {
	public:
	int spanningTree(int V, vector<vector<int>> & edges) {
		vector<vector<pair<int, int>> >adj(V);
		
		for (int i = 0; i<edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
		vector<int>vis(V, 0);
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;
			if (vis[node] == 1)
				continue;
			
			vis[node] = 1;
			sum += wt;
			for (auto it:adj[node]) {
				int adjNode = it.first;
				int edW = it.second;
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
		
	}
};
