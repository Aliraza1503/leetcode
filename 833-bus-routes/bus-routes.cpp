class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
       int n = routes.size();
       unordered_map<int,vector<int>> adj;
       vector<int> vis(n,0);
       for(int i =0;i<n;i++){
        for(auto it:routes[i]){
            adj[it].push_back(i);
        }
       }
       if(source ==target) return 0;
       queue<pair<int,int>> q;
       for(auto it:adj[source]){
        q.push({it,1});
        vis[it]=1;
       }
        while(!q.empty()){
            auto[val,freq]=q.front();
            q.pop();
            for(auto it:routes[val]){
                for(auto jt:adj[it]){
                    if(vis[jt]==0){
                        q.push({jt,freq+1});
                        vis[jt]=1;
                    }
                    if(it==target){
                        return freq;
                    }
                }
            }
        }
        return -1;
    }
};