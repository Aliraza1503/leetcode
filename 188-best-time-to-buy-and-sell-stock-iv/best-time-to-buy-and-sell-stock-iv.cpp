class Solution {
public:
     int n;
    int dp[100000][2][101];
    int solve(int i,int check,int total,vector<int>&prices){
        if(i>=n||total==0) return 0;
        int b=0,nb=0,s=0,ns=0;
        if(dp[i][check][total]!=-1) return dp[i][check][total];
        if(check==0){
            b=-prices[i]+solve(i+1,1,total,prices);
            nb = solve(i+1,0,total,prices);
        }
        if(check==1){
            s=prices[i]+solve(i+1,0,total-1,prices);
            ns = solve(i+1,1,total,prices);
        }
        return dp[i][check][total]= max(max(b,nb),max(s,ns));
    }
    int maxProfit(int k, vector<int>& prices) {
         n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,k,prices); 
    }
};