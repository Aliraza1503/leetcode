class Solution {
public:
    typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto it:roads){
            mp[it[0]].push_back({it[1],it[2]});
            mp[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
        vector<ll> store(n,LLONG_MAX);
        pq.push({0,0});
        store[0]=0;
        while(!pq.empty()){
            auto val= pq.top();
            pq.pop();
            long long curtime = val.first;
            int idx = val.second;
            if(curtime>store[idx]) continue;
            for(auto it:mp[idx]){
                long long  temp = it.second+curtime;
                if(temp<store[it.first]){
                    store[it.first]=temp;
                    pq.push({temp,it.first});
                }
            }
        }
        int ans = store[n-1];
             vector<ll> nig(n,LLONG_MAX);
        pq.push({0,0});
        nig[0]=0;
        int check = 0;
        int mod = 1e9 + 7;
        vector<ll> ways(n,0);
        ways[0]=1;
        while(!pq.empty()){
            auto val= pq.top();
            pq.pop();
            long long curtime = val.first;
            int idx = val.second;
            if(curtime>nig[idx]) continue;
            for(auto it:mp[idx]){
                long long temp = it.second+curtime;
                
                if(temp<nig[it.first]){
                    nig[it.first]=temp;
                    ways[it.first]=ways[idx];
                    pq.push({temp,it.first});
                }
               else if(temp ==nig[it.first]){
                ways[it.first]=(ways[it.first]+ways[idx])%mod;
               }
            }
        }
        return ways[n-1];;
    }
};