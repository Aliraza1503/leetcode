class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // {neighbor, cost}: cost is 1 for original direction (away from 0), 0 for reverse
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : connections) {
            adj[edge[0]].push_back({edge[1], 1});
            adj[edge[1]].push_back({edge[0], 0});
        }

        queue<int> q;
        vector<bool> vis(n, false);
        
        q.push(0);
        vis[0] = true;
        
        int changes = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (auto& [next, cost] : adj[curr]) {
                if (!vis[next]) {
                    vis[next] = true;
                    changes += cost;
                    q.push(next);
                }
            }
        }
        
        return changes;
    }
};