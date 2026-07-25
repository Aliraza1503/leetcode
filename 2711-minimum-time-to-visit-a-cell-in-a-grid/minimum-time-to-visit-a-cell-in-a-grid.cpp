class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> store(n,vector<int>(m,INT_MAX));
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
       pq.push({0,{0,0}});
       if(grid[0][1]>1&&grid[1][0]>1) return -1;
       store[0][0]=0;
       vector<int> row={-1,0,1,0};
       vector<int> col = {0,-1,0,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int curtime = it.first+1;
            int i = it.second.first;
            int j = it.second.second;
            if(i==n-1&&j==m-1) return curtime-1;
            for(int k =0;k<4;k++){
                int i1 = i+row[k];
                int j1 = j+col[k];
                if(i1>=0&&i1<n&&j1>=0&&j1<m){
                    int newtime = curtime;
                         if (newtime< grid[i1][j1]) {

                        int diff = grid[i1][j1] - newtime;

                        if (diff % 2 == 0)
                            newtime = grid[i1][j1];
                        else
                    newtime = grid[i1][j1] + 1;
                    }
                            if(newtime<store[i1][j1]){
                                store[i1][j1]=newtime;
                                  pq.push({newtime,{i1,j1}});
                            }
                }
            }
        }
        return store[n-1][m-1]==INT_MAX?-1:store[n-1][m-1];
    }
};