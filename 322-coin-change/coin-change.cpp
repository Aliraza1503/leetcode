class Solution {
public:
    int n;
    int dp[10001];
    int solve(int amount,vector<int>&coins){
        if(amount==0) return 0;
        int ans =1e5;
        if(dp[amount]!=-1) return dp[amount];
        for(int i=0;i<n;i++){
            if(amount-coins[i]>=0){
                int take = 1+solve(amount-coins[i],coins);
                ans = min(ans,take);
            }
        }
        return dp[amount]= ans;
    }
    int coinChange(vector<int>& coins, int amount) {
     n = coins.size();
     memset(dp,-1,sizeof(dp));
     return solve(amount,coins)==1e5?-1:solve(amount,coins);
    }
};