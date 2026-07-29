class Solution {
public:
    int n;
    bool bfs(unordered_map<int,vector<int>> &adj,int u,int v){
        vector<int> vis(n+1,-1);
        queue<int> q;
        q.push(u);
        vis[u]=1;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            for(auto it:adj[val]){
                if(it==v){return true;}
                if(vis[it]==-1){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         n = edges.size();
        unordered_map<int,vector<int>> adj;
        for(int i =0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
         
            if(adj.find(u)!=adj.end()&&adj.find(v)!=adj.end()&&bfs(adj,u,v)){
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return edges[0] ;
    }
};