class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int fresh =0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        vector<int> row = {-1,0,1,0};
        vector<int> col ={0,1,0,-1};
        int ans =0;
        while(!q.empty()&&fresh>0){
           int time = q.front().second;
            int s = q.size();
            for(int t =0;t<s;t++){
                 auto it = q.front();
            q.pop();
            int i =it.first.first;
            int j = it.first.second;
            
            // ans = max(ans,time);
            for(int p =0;p<4;p++){
                int i1 = i+row[p];
                int j1 = j+col[p];
                if(i1>=0&&i1<n&&j1>=0&&j1<m&&grid[i1][j1]==1){
                    q.push({{i1,j1},time+1});
                    fresh--;
                    ans = max(ans,time+1);
                    grid[i1][j1]=2;
                }
            }
            }
        }
        return fresh>0?-1:ans;
    }
};