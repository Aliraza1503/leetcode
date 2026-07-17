class Solution {
public:
    int n, m;
    int dp[501][501];
    int solve(int i,int j,string &w1,string&w2){
        if(j==m) return n-i;
        if(i==n) return m-j;
        int take = 1e5;
        int replace = 1e5;
        int del = 1e5;
        int ins=1e5;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]){
           take= solve(i+1,j+1,w1,w2);
        }
        else{
         replace = 1 + solve(i+1,j+1,w1,w2);
        del = 1 + solve(i+1,j,w1,w2);
        ins = 1 + solve(i,j+1,w1,w2);
        }
        return dp[i][j]= min(min(ins,replace),min(take,del));
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
         m = word2.size();
       memset(dp,-1,sizeof(dp));
        return  solve(0,0,word1,word2);
    }
};