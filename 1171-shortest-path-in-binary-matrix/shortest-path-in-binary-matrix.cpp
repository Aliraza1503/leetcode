class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        if(n==1&&grid[0][0]==0) return 1;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int freq = it.second;
            if(r+1<n&&grid[r+1][c]==0&&vis[r+1][c]==0){
                q.push({{r+1,c},freq+1});
                vis[r+1][c]=1;
                if(r+1==n-1&&c==n-1) return freq+1;
            }
             if(r-1>=0&&grid[r-1][c]==0&&vis[r-1][c]==0){
                q.push({{r-1,c},freq+1});
                vis[r-1][c]=1;
            }
            if(r+1<n&&c+1<n&&grid[r+1][c+1]==0&&vis[r+1][c+1]==0){
                q.push({{r+1,c+1},freq+1});
                vis[r+1][c+1]=1;
                 if(r+1==n-1&&c+1==n-1) return freq+1;
            }
               if(r-1>=0&&c-1>=0&&grid[r-1][c-1]==0&&vis[r-1][c-1]==0){
                q.push({{r-1,c-1},freq+1});
                vis[r-1][c-1]=1;
            }
               if(r+1<n&&c-1>=0&&grid[r+1][c-1]==0&&vis[r+1][c-1]==0){
                q.push({{r+1,c-1},freq+1}); 
                vis[r+1][c-1]=1;
            }
               if(r-1>=0&&c+1<n&&grid[r-1][c+1]==0&&vis[r-1][c+1]==0){
                q.push({{r-1,c+1},freq+1});
                vis[r-1][c+1]=1;
            }
            if(c+1<n&&grid[r][c+1]==0&&vis[r][c+1]==0){
                q.push({{r,c+1},freq+1});
                vis[r][c+1]=1;
                 if(r==n-1&&c+1==n-1) return freq+1;
            }
            if(c-1>=0&&grid[r][c-1]==0&&vis[r][c-1]==0){
                q.push({{r,c-1},freq+1});
                vis[r][c-1]=1;
            }
        }
        return -1;
    }
};