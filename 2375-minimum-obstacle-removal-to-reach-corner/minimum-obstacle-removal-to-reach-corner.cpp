class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>> store(n,vector<int>(m,INT_MAX));
        store[0][0]=0;
        pq.push({0,{0,0}});
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,-1,0,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cur = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if(i==n-1&&j==m-1) return cur;
            for(int k=0;k<4;k++){
                int p = i+row[k];
                int q = j+col[k];
                if(p>=0&&p<n&&q>=0&&q<m){
                    if(grid[p][q]==0){
                        if(store[p][q]>cur){
                            store[p][q]=cur;
                            pq.push({cur,{p,q}});
                        }
                    }
                    else{
                        if(store[p][q]>cur+1){
                            store[p][q]=cur+1;
                            pq.push({cur+1,{p,q}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};