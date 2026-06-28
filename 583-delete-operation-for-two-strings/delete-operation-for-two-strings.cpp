class Solution {
public:
    int n;
    int m;
    int dp[501][501];
    int solve(int i,int j,string&s1,string&s2){
        if(i>=n||j>=m){ return 0;}
        if(dp[i][j]!=-1) return dp[i][j];
        int take =0;
        if(s1[i]==s2[j]){
            take = 1+solve(i+1,j+1,s1,s2);
        }
        int skipleft = solve(i+1,j,s1,s2);
        int skipright = solve(i,j+1,s1,s2);
        return dp[i][j]= max(take,max(skipleft,skipright));
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        memset(dp,-1,sizeof(dp));
        int val=solve(0,0,word1,word2);
        
        return (n+m)-(2*val);
    }
};