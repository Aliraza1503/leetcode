class Solution {
public:
    int dp[1001];
    int n;
    int solve(int i,vector<int>&cost){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take1 = cost[i]+solve(i+1,cost);
        int take2 = cost[i]+solve(i+2,cost);
        return dp[i]= min(take1,take2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memset(dp,-1,sizeof(dp));
        // return min(solve(0,cost),solve(1,cost));
        vector<int> dpp(n+2,0);
        for(int i=n-1;i>=0;i--){
            dpp[i]=cost[i]+min(dpp[i+1],dpp[i+2]);
        }
        return min(dpp[0],dpp[1]);
    }
};