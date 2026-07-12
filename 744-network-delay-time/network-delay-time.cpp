class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> store(n+1,INT_MAX);
        store[k]=0;
        pq.push({0,k});
        unordered_map<int,vector<pair<int,int>>> adj;
        int m = times.size();
        for(auto it:times){
                int src = it[0];
                int dest = it[1];
                int val = it[2];
                adj[src].push_back({dest,val}); 
        }
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode = it.first;
                int wt = it.second;
                if(dist+wt<store[adjnode]){
                    store[adjnode]=wt+dist;
                    pq.push({wt+dist,adjnode});
                }
            }
        }
        int ans = 0;
        for(auto i=1;i<store.size();i++){
           if(store[i]==INT_MAX) {return -1;}
           ans = max(ans,store[i]);
        }
        return ans;
    }
};