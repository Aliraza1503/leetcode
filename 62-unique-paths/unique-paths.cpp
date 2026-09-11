class Solution {
public:
    int dp[101][101];
    int solve(int i,int j,int m,int n){
        if(i>=n||j>=m) return 0;
        if(i==n-1&&j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = solve(i+1,j,m,n);
        int down = solve(i,j+1,m,n);
        return dp[i][j]= right + down;
    }
    int uniquePaths(int m, int n) {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,m,n);
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1){
                dp[i][j]=1;
                continue;
            }
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
        }
       }
       return dp[n][m];
    }
};