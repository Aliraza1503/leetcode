class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> store(n,vector<int>(m,INT_MAX));
       
      priority_queue< pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>> pq;
      pq.push({0,{0,0}});
      store[0][0]=0;
      while(!pq.empty()){
        int val = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if(c+1<m){
            int diff = abs(heights[r][c]-heights[r][c+1]);
            if(max(diff,val)<store[r][c+1]){
                store[r][c+1]=max(diff,val);
                pq.push({max(diff,val),{r,c+1}});
            }
        }
        if(r+1<n){
            int diff = abs(heights[r][c]-heights[r+1][c]);
            if(max(diff,val)<store[r+1][c]){
                store[r+1][c]=max(diff,val);
                pq.push({max(diff,val),{r+1,c}});
            }
        }
        if(c-1>=0){
            int diff = abs(heights[r][c-1]-heights[r][c]);
            if(max(diff,val)<  store[r][c-1]){
                store[r][c-1]=max(diff,val);
                pq.push({max(diff,val),{r,c-1}});
            }
        }
        if(r-1>=0){
            int diff = abs(heights[r-1][c]-heights[r][c]);
            if(  max(diff,val)< store[r-1][c]){
               store[r-1][c] =max(diff,val);
                pq.push({max(diff,val),{r-1,c}});
            }
        }
      }
      return store[n-1][m-1];
    }
};