class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n,false);
        long long ans = 1LL*n*(n-1)/2;
        for(int i =0;i<n;i++){
            queue<int> q;
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                int cnt =0;
                while(!q.empty()){
                    int val = q.front();
                    q.pop();
                    cnt++;
                    for(auto it:adj[val]){
                        if(!vis[it]){
                        vis[it]=true;
                        q.push(it);
                        }
                    }
                }
                long long temp = 1LL*cnt*(cnt-1)/2;
                ans-=temp;
            }
        }
        return ans;
    }
};