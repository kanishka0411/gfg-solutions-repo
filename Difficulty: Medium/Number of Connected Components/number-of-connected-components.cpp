class Solution {
	public:
	void bfs(int node, vector<int>adj[], vector<int>&vis) {
		vis[node] = 1;
		queue<int>q;
		q.push(node);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (auto it:adj[node]) {
				if (!vis[it]) {
					vis[it] = 1;
					q.push(it);
				}
			}
		}
		
	}
	int countConnected(int V, vector<vector<int>> & edges) {
		vector<int>adj[V];
		vector<int>vis(V, 0);
		int n = edges.size();
		for (int i = 0; i<n; i++) {
			adj[edges[i][0]].push_back(edges[i][1]);
			adj[edges[i][1]].push_back(edges[i][0]);
		}
		
		int cnt = 0;
		for (int i = 0; i<V; i++) {
			if (!vis[i]) {
				cnt++;
				bfs(i, adj, vis);
			}
		}
		return cnt;
		
	}
};
