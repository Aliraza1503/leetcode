class Solution {
public:
    bool dfs(int node,vector<int>&vis,unordered_map<int,vector<int>>&mp){
        if(vis[node]==1) return true;
        vis[node]=1;
        for(auto it:mp[node]){
            if(vis[it]==1) return true;
            else if(vis[it]==0){
                if(dfs(it,vis,mp)) return true;
            }
        }
        vis[node]=2;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        //firstly i will solve it using bfs method which is also called as kahns algorithm
        unordered_map<int,vector<int>> mp;

      //  vector<int> indeg(num,0);
        for(auto it:pre){
            mp[it[1]].push_back(it[0]);
           // indeg[it[0]]++;
        }
        vector<int> vis(num,0);
        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(dfs(i,vis,mp)) return false;
            }
        }
        // queue<int> q;
        // for(int i=0;i<num;i++){
        //     if(indeg[i]==0){
        //         q.push(i);
        //     }
        // }
        // vector<int> ans;
        // while(!q.empty()){
        //     int val = q.front();
        //     q.pop();
        //     ans.push_back(val);
        //     for(auto it:mp[val]){
        //         indeg[it]--;
        //         if(indeg[it]==0){
        //             q.push(it);
        //         }
        //     }
        // };
        // return ans.size()==num;
            return true;
    }
};