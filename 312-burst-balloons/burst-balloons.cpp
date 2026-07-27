class Solution {
public:
    int n;
    int dp[303][303];
    int solve(int i,int j,vector<int>&nums){
       if(i>j) return 0;
       int ans =0;
       if(dp[i][j]!=-1) return dp[i][j];
       for(int k=i;k<=j;k++){
        int coins = nums[i-1]*nums[k]*nums[j+1];
        int left = solve(i,k-1,nums);
        int right = solve(k+1,j,nums);
        ans = max(ans,coins+left+right);
       }
       return dp[i][j]= ans;
    }
    int maxCoins(vector<int>& nums) {
       
        nums.push_back(1);
        nums.insert(nums.begin(),1);
         n = nums.size();
         memset(dp,-1,sizeof(dp));
        return solve(1,n-2,nums);
    }
};