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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        queue<int> q;
        int cnt =0;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                cnt++;
                solve(i,vis,adj);
                // q.push(i);
                // vis[i]=true;
                // while(!q.empty()){
                //     int val = q.front();
             
                //     q.pop();
                //     for(auto it:adj[val]){
                //         if(!vis[it]){
                //             q.push(it);
                //             vis[it]=true;
                //         }
                //     }
                // }
            }
        }
        return cnt;
    }
};