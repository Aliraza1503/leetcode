class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,adj,vis);
            }
        }
    }
    void bfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis){
        
    }
    int findCircleNum(vector<vector<int>>& nums) {
         unordered_map<int,vector<int>>adj;
         int n = nums.size();
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(i!=j&&nums[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n,0);
        int ans =0;
        queue<int> q;
        
        for(int i =0;i<n;i++){
            if(vis[i]==0){
           q.push(i); 
            while(!q.empty()){
                int val = q.front();
                vis[val]=1;
                q.pop();
                for(auto it:adj[val]){
                    if(vis[it]==0){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
            ans++;
            }

        }
        return ans;
    }
};