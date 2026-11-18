class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
      
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(s);
        vector<bool>vis(n,false);
        vis[s]=true;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(auto it:adj[val]){
                if(!vis[it])
                q.push(it);
                vis[it]=true;
            }
        }
        return vis[d]==true;
    }
};