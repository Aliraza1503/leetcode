class Solution {
public:
    int n;
    
    int solve(int i,int j,vector<vector<int>>&triangle, vector<vector<int>> &dp){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int down = triangle[i][j]+solve(i+1,j,triangle,dp);
        int right = triangle[i][j]+solve(i+1,j+1,triangle,dp);
        return dp[i][j]= min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        return solve(0,0,triangle,dp);
    }
};