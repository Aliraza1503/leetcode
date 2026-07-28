class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto it:edges){
            mp[it[0]].push_back({it[2],it[1]});
            mp[it[1]].push_back({it[2],it[0]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> store(disappear.size(),INT_MAX);
        store[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cur = it.first;
            int idx = it.second;
            if(cur>store[idx]) continue;
            for(auto val:mp[idx]){
                if(cur+val.first<store[val.second]&&cur+val.first<disappear[val.second]){
                    store[val.second]=cur+val.first;
                    pq.push({cur+val.first,val.second});
                }
            }
        }
        // int n = disappear.size();
        for(int i=1;i<n;i++){
            if(store[i]>disappear[i]){
                    store[i]=-1;
            }
        }
        return store;
    }
};