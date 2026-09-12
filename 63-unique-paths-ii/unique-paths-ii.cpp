class Solution {
public:
    int n,m;
    // int dp[101][101];
    // int solve(int i,int j,vector<vector<int>>&og){
    //     if(i>=n||j>=m||og[i][j]==1) return 0;
    //     if(i==n-1&&j==m-1) return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down = solve(i+1,j,og);
    //     int right = solve(i,j+1,og);
    //     return  dp[i][j]=down+right;

    // }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        n = og.size();
        m = og[0].size();
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,og);

        vector<vector<int>> dp(n,vector<int>(m,0));
        if(og[0][0]==1) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) dp[0][0]=1;
                else if(og[i][j]==0){
                    int right = (i>0)?dp[i-1][j]:0;
                    int down = (j>0)?dp[i][j-1]:0;
                    dp[i][j]=right+down;
                }
            }
        }
     return dp[n-1][m-1];

    }
};