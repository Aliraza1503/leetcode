class Solution {
public:
    int n;
    int dp[1001][1001];
    int solve(int i,int j,string&s){
        if(i==j) return 1;
        if(i>j) return 0;
        int take = 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            take = 2 + solve(i+1,j-1,s);
        }
        int left = solve(i+1,j,s);
        int right = solve(i,j-1,s);
        return dp[i][j]= max(take,max(right,left));
    }
    int longestPalindromeSubseq(string s) {
         n= s.size();
         memset(dp,-1,sizeof(dp));
         return solve(0,n-1,s);
    }
};