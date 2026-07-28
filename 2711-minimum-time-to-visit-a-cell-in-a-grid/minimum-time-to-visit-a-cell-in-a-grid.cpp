class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>> store(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        if(grid[0][1]>1&&grid[1][0]>1) return -1;
        store[0][0]=0;
        pq.push({0,{0,0}});
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cur = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if(i==n-1&&j==m-1) return cur;
            for(int k=0;k<4;k++){
                int i1 = i+row[k];
                int j1 = j+col[k];
                if(i1>=0&&i1<n&&j1>=0&&j1<m){
                    if(cur+1-grid[i1][j1]>=0){
                        if(store[i1][j1]>cur+1){
                            store[i1][j1]=cur+1;
                            pq.push({cur+1,{i1,j1}});
                        }
                    }
                    else {
                        int cnt = grid[i1][j1]-cur;
                        if(cnt%2==0){
                            if(cur+cnt+1<store[i1][j1]){
                                store[i1][j1]=cur+cnt+1;
                                pq.push({cur+cnt+1,{i1,j1}});
                            }
                        }
                        else{
                            if(cur+cnt<store[i1][j1]){
                                store[i1][j1]=cur+cnt;
                                pq.push({cur+cnt,{i1,j1}});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};