
        class Solution {
public:
    typedef long long ll;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<ll>> store(n,vector<ll>(m,LLONG_MAX));
        priority_queue<pair<ll,pair<pair<int,int>,int>>,vector<pair<ll,pair<pair<int,int>,int>>>,greater<pair<ll,pair<pair<int,int>,int>>>> pq;
        pq.push({0,{{0,0},0}});
        store[0][0]=0;
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,-1,0,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int curtime = it.first;
            int i = it.second.first.first;
            int j = it.second.first.second;
            int check = it.second.second;
            if(i==n-1&&j==m-1) {return curtime;}
            for(int k = 0;k<4;k++){
                int i1 = i+row[k];
                int j1 = j+col[k];
                if(i1>=0&&i1<n&&j1>=0&&j1<m){
                    int wait =max(0,moveTime[i1][j1]-curtime);
                    int fin = 0;
                    int newcheck = 1 - check;
                    if(check==0){
                     fin = wait+curtime+1;
                    }
                    else {
                         fin = wait+curtime+2;
                    }
                    if(store[i1][j1]>fin){
                        store[i1][j1]=fin;
                        pq.push({fin,{{i1,j1},newcheck}});
                    }
                }
            }
        }
        return 0;
    }
};
