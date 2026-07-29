class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int i =0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i!=j){
                    int ff = points[i][0];
                    int fs = points[i][1];
                    int sf = points[j][0];
                    int ss = points[j][1];
                    mp[i].push_back({abs(sf-ff)+abs(ss-fs),j});
                    mp[j].push_back({abs(sf-ff)+abs(ss-fs),i});
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<bool> isvis(n,false);
        int ans =0;
        pq.push({0,{0,-1}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cur = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            if(isvis[node]==true)continue;
            if(isvis[node]==false){
                ans+=cur;
                isvis[node]=true;
            }
            for(auto val :mp[node]){
                int point = val.first;
                int neighnode = val.second;
                if(isvis[neighnode]==false){
                    pq.push({point,{neighnode,node}});
                }
            }
        }
        return ans;
    }
};