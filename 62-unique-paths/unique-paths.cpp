class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(i==0&&j==0){continue;}
            
            int right = (i-1>=0)?dp[i-1][j]:0;
            int down = (j-1>=0)?dp[i][j-1]:0;
            dp[i][j]=right+down;
        }
        }
        return dp[n-1][m-1];
    }
};