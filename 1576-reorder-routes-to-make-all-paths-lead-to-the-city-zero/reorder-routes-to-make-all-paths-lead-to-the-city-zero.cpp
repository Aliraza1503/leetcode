class Solution {
public:
    int dfs(int curr, int parent, vector<vector<pair<int, int>>>& adj) {
        int changes = 0;
        for (auto& [next, cost] : adj[curr]) {
            if (next != parent) {
                changes += cost + dfs(next, curr, adj);
            }
        }
        return changes;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        // {neighbor, cost}: cost is 1 for original direction (away from 0), 0 for reverse
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : connections) {
            adj[edge[0]].push_back({edge[1], 1});
            adj[edge[1]].push_back({edge[0], 0});
        }
        
        return dfs(0, -1, adj);
    }
};