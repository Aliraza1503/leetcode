class Solution {
public:
    int n;
    int dp[201][10001];
    bool solve(int i,int target,vector<int>&nums){
        if(i>=n) return false;
        if(target==0) return true;
        if(target<0) return false;
        if(dp[i][target]!=-1) return dp[i][target];
      bool  take = solve(i+1,target-nums[i],nums);
      if(take) return dp[i][target]= true;
      bool ntake = solve(i+1,target,nums);
      return dp[i][target]= ntake;

    }
    bool canPartition(vector<int>& nums) {
        int val=0;
        n = nums.size();
        for(auto it:nums){
            val+=it;
        }
        if(val%2!=0) return false;
        int tar = val/2;
        memset(dp,-1,sizeof(dp));
        return solve(0,tar,nums);
        int n = nums.size();
        vector<vector<bool>> dp(n,vector<bool>(tar,0));
    }
};