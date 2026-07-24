class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int check) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto it:edges){
            mp[it[0]].push_back({it[2],it[1]});
            mp[it[1]].push_back({it[2],it[0]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int ans =0;
        int finst = INT_MAX;
        for(int i=0;i<n;i++){
            pq.push({0,i});
            vector<int> store(n,INT_MAX);
            store[i]=0;
            while(!pq.empty()){
                auto it= pq.top();
                pq.pop();
                int cur = it.first;
                int idx = it.second;
                for(auto val:mp[idx]){
                    int temp = cur+val.first;
                    int negidx = val.second;
                    if(temp<store[negidx]){
                        store[negidx]=temp;
                        pq.push({temp,negidx});
                    }
                }
            }
            int st =0;
            for(auto it:store){
                if(it<=check){
                    st++;
                }
            }
            if(st<=finst){
                ans = i;
                finst = st;
            }
        }
        return ans;
    }
};