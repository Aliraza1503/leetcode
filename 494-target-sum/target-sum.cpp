class Solution {
public:
    int n;
    int solve(int i,int cur,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(i==n){
            return cur==target;
        }
        int temp = 20000+cur;
        if(dp[i][temp]!=INT_MAX) return dp[i][temp];
        int takeplus = solve(i+1,cur+nums[i],target,nums,dp);
        int takeminus = solve(i+1,cur-nums[i],target,nums,dp);
        return dp[i][temp]= takeplus+takeminus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(40001,INT_MAX));
        return solve(0,0,target,nums,dp);
    }
};