class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> store(n,vector<int>(m,INT_MAX));
        store[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int cur = it.first;
            int i = it.second.first;
            int j = it.second.second;
            if(cur>store[i][j]) continue;
            for(int k=0;k<4;k++){
                int p = i+row[k];
                int q = j+col[k];
                if(p>=0&&p<n&&q>=0&&q<m){
                    int val =max(cur,abs(heights[p][q]-heights[i][j]));
                    if(store[p][q]>val){
                        store[p][q]=val;
                        pq.push({val,{p,q}});
                    }
                }
            }
        }
        return store[n-1][m-1];
    }
};