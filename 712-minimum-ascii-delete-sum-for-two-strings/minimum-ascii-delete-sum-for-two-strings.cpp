class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int solve(int i,int j,string&s1,string&s2){
        if(i>=n||j>=m) return 0;
        int take =0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            take = 2*s1[i]+solve(i+1,j+1,s1,s2);
        }
        int takeleft = solve(i+1,j,s1,s2);
        int takeright = solve(i,j+1,s1,s2);
        return dp[i][j]= max(take,max(takeleft,takeright));
    }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        int s1val=0;
        int s2val=0;
        for(auto it:s1){
            s1val+=it;
        }
        for(auto it:s2){
            s2val+=it;
        }
        memset(dp,-1,sizeof(dp));
        return s1val+s2val-solve(0,0,s1,s2);
    }
};