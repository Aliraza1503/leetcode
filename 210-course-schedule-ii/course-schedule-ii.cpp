class Solution {
public:
    bool dfs(int i, unordered_map<int,vector<int>> &mp, vector<int> &vis,vector<int>&ans){
        vis[i]=1;
        for(auto it:mp[i]){
            if(vis[it]==1) return true;
            else if(vis[it]==0){
                if(dfs(it,mp,vis,ans)) return true;
            }
        }
        vis[i]=2;
        ans.push_back(i);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> mp;
        for(auto it:pre){
            mp[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,mp,vis,ans);
            }
        }
        vector<int> store;
        reverse(ans.begin(),ans.end());
        return ans.size()==n?ans:store;
    }
};