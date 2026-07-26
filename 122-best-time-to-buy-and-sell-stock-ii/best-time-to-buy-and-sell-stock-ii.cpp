class Solution {
public:
    int n;
    int dp[30000][2];
    int solve(int i,int check,vector<int>&prices){
        if(i>=n) return 0;
       int b=0,nb=0,s=0,ns=0;
       if(dp[i][check]!=-1) return dp[i][check];
       if(check==0){
        b =-prices[i]+solve(i+1,1,prices);
        nb = solve(i+1,0,prices);
       }
       if(check==1){
        s = prices[i]+solve(i+1,0,prices);
        ns = solve(i+1,1,prices);
       }
       return dp[i][check]= max(max(b,nb),max(s,ns));

    }
    int maxProfit(vector<int>& prices) {
       n = prices.size();
       memset(dp,-1,sizeof(dp));
       return solve(0,0,prices); 
    }
};