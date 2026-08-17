class Solution {
public:
    int dp[201][201];
    int n,m;
    int solve(int r,int c,vector<vector<int>>&matrix){
        if(dp[r][c]!=-1) return dp[r][c];
        dp[r][c]=1;
        vector<int> row = {-1,0,1,0};
        vector<int> col = {0,-1,0,1};
        for(int k =0;k<4;k++){
            int r1 = r+row[k];
            int c1 = c+col[k];
            if(r1>=0&&r1<n&&c1>=0&&c1<m&&matrix[r1][c1]>matrix[r][c]){
                dp[r][c]=max(dp[r][c],1+solve(r1,c1,matrix));
            }
        }
        return dp[r][c];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //this is a dp problem,it will give tle when solve through graph 
         n = matrix.size();
         m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                ans = max(ans,solve(i,j,matrix));
            }
        }
        return ans;

    }
};