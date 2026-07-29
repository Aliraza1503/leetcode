class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto it:roads){
            mp[it[0]].push_back({it[2],it[1]});
            mp[it[1]].push_back({it[2],it[0]});
        }
        vector<bool> vis(n+1,false);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int val =0;
        int ans = INT_MAX;
        pq.push({0,{1,-1}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cur = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            if(vis[node]==true)continue;
            if(vis[node]==false){
                if(cur!=0){
                    ans = min(cur,ans);
                }
                val+=cur;
                vis[node]=true;
            }
            for(auto temp :mp[node]){
                int check = temp.first;
                int neighnode = temp.second;
                if(vis[neighnode]==false){
                    pq.push({check,{neighnode,node}});
                }
            }
        }
        return ans;
    }
};