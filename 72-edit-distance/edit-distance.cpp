class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(int i,int j,string&s1,string&s2){
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int insert = 1e5;
        int del = 1e5;
        int replace = 1e5;
     
        if(s1[i]==s2[j]){
        return dp[i][j]= solve(i+1,j+1,s1,s2);
        }
        else {
            insert = 1 + solve(i,j+1,s1,s2);
            del = 1 + solve(i+1,j,s1,s2);
            replace = 1+solve(i+1,j+1,s1,s2);
        }
        return dp[i][j]= min(insert,min(del,replace));
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        
        // if(n>=m){
        //      temp = word1;
        // }
        // else{
        //     temp = word2;
        // }
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2);
    }
};