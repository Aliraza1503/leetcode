class Solution {
public:
    int dp[46];
    int solve(int n){
         if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
        // memset(dp,-1,sizeof(dp));
        vector<int> dp(n+1,1);
        for(int i =2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

    //    return solve(n);
    return dp[n];
    }
};