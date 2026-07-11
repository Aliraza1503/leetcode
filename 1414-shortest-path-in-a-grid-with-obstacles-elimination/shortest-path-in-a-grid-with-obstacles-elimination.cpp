class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        if (n == 1 && m == 1) return 0;

        queue<pair<pair<int,int>,pair<int,int>>> q;
        vector<vector<vector<int>>> vis(
            n, vector<vector<int>>(m, vector<int>(k + 1, 0))
        );

        q.push({{0,0},{0,k}});
        vis[0][0][k] = 1;

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int freq = it.second.first;
            int p = it.second.second;

            if(r == n-1 && c == m-1)
                return freq;

            // Down
            if(r + 1 < n){
                if(grid[r+1][c] == 0){
                    if(!vis[r+1][c][p]){
                        vis[r+1][c][p] = 1;
                        q.push({{r+1,c},{freq+1,p}});
                    }
                }
                else if(p > 0){
                    if(!vis[r+1][c][p-1]){
                        vis[r+1][c][p-1] = 1;
                        q.push({{r+1,c},{freq+1,p-1}});
                    }
                }
            }

            // Right
            if(c + 1 < m){
                if(grid[r][c+1] == 0){
                    if(!vis[r][c+1][p]){
                        vis[r][c+1][p] = 1;
                        q.push({{r,c+1},{freq+1,p}});
                    }
                }
                else if(p > 0){
                    if(!vis[r][c+1][p-1]){
                        vis[r][c+1][p-1] = 1;
                        q.push({{r,c+1},{freq+1,p-1}});
                    }
                }
            }

            // Left
            if(c - 1 >= 0){
                if(grid[r][c-1] == 0){
                    if(!vis[r][c-1][p]){
                        vis[r][c-1][p] = 1;
                        q.push({{r,c-1},{freq+1,p}});
                    }
                }
                else if(p > 0){
                    if(!vis[r][c-1][p-1]){
                        vis[r][c-1][p-1] = 1;
                        q.push({{r,c-1},{freq+1,p-1}});
                    }
                }
            }

            // Up
            if(r - 1 >= 0){
                if(grid[r-1][c] == 0){
                    if(!vis[r-1][c][p]){
                        vis[r-1][c][p] = 1;
                        q.push({{r-1,c},{freq+1,p}});
                    }
                }
                else if(p > 0){
                    if(!vis[r-1][c][p-1]){
                        vis[r-1][c][p-1] = 1;
                        q.push({{r-1,c},{freq+1,p-1}});
                    }
                }
            }
        }

        return -1;
    }
};