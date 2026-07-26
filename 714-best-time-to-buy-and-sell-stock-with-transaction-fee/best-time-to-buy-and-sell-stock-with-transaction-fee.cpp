class Solution {
public:
    int n;
    int dp[50001][2];
    int solve(int i,vector<int>&prices,int fee,int check){
        if(i>=n) return 0;
        int buy =0;
        if(dp[i][check]!=-1) return dp[i][check];
        int sell = 0;
        if(check==0){
            int b= -prices[i]+solve(i+1,prices,fee,1);
            int nb = solve(i+1,prices,fee,0);
            buy = max(b,nb);
        }
        else{
            int s = (prices[i]-fee)+solve(i+1,prices,fee,0);
            int ns  = solve(i+1,prices,fee,1);
            sell = max(s,ns);
        }
        return dp[i][check]= max(sell,buy);
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,fee,0);
    }
};