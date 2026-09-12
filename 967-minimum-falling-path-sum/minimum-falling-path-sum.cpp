class Solution {
public:
    int n;
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
      if(i==n-1) return matrix[i][j];
    //   if(j>=n||j<0) return 1e5;
    if(dp[i][j]!=INT_MAX) return dp[i][j];
      int down = matrix[i][j]+solve(i+1,j,matrix,dp);
      int left = j>0?matrix[i][j]+solve(i+1,j-1,matrix,dp):1e5;
      int right = j<n-1?matrix[i][j]+solve(i+1,j+1,matrix,dp):1e5;
      return dp[i][j]= min({down,left,right});  
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
         n = matrix.size();
        int val = INT_MAX;
        // for(int i=0;i<n;i++){
        //     vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        //     val =min(val,solve(0,i,matrix,dp));
        // }
        // return val;
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j]+dp[i-1][j];
                int left = matrix[i][j]+(j>0?dp[i-1][j-1]:1e5);
                int right = matrix[i][j]+(j<n-1?dp[i-1][j+1]:1e5);
                dp[i][j]=min({up,left,right});
            }
        }
        for(int i=0;i<n;i++){
            val = min(val,dp[n-1][i]);
        }
        return val;

    }
};