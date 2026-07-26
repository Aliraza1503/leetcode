class Solution {
public:
 
   
    int solve(int i ,vector<int>& prices,int indicate,int n,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][indicate]!=-1) return dp[i][indicate];
        if(indicate==0){
            int buy = solve(i+1,prices,1,n,dp)-prices[i];
            int notbuy =solve(i+1,prices,0,n,dp);
          return  dp[i][indicate]= max(buy,notbuy);
        }
      
        else {
            int sell = prices[i]+solve(i+2,prices,0,n,dp);
            int notsell = solve(i+1,prices,1,n,dp);
           return   dp[i][indicate]= max(sell,notsell);
        }
     
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,prices,0,n,dp);
    }
};