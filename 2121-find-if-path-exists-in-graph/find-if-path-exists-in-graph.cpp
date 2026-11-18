class Solution {
public:
    void solve(int node,vector<bool>&vis,vector<vector<int>>&adj){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                solve(it,vis,adj);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
      
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(s);
        vector<bool>vis(n,false);
        // This is for bfs part
        // vis[s]=true;
        // while(!q.empty()){
        //     int val = q.front();
        //     q.pop();
        //     for(auto it:adj[val]){
        //         if(!vis[it])
        //         q.push(it);
        //         vis[it]=true;
        //     }
        // }
        solve(s,vis,adj);
        return vis[d]==true;
    }
};