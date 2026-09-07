class Solution {
public:
    void dfs(int i, unordered_map<int,vector<int>>& mp,int &val,int &ans,vector<int>&vis,vector<int>&quiet){
        vis[i]=1;
        if(quiet[i]<=val){
            val = quiet[i];
            ans = i;
        }
        for(auto it:mp[i]){
            if(vis[it]==0){
                dfs(it,mp,val,ans,vis,quiet);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int,vector<int>> mp;
        for(auto it:richer){
            mp[it[1]].push_back(it[0]);
        }
        vector<int> store(n);
        for(int i=0;i<n;i++){
            store[i]=i;
        }
        for(int i=0;i<n;i++){
            int val = INT_MAX;
            int ans = i;
            vector<int> vis(n,0);
           dfs(i,mp,val,ans,vis,quiet);
           if(ans!=INT_MAX){
            store[i]=ans;
           }
        }
        return store;
    }
};