class Solution {
public:
    int n,m;
   
    bool solve(int i,int j ,string&s1,string&s2,string&s3,vector<vector<int>>&dp){
        if(i==n&&j==m){
             return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool check =false;
        if(i<n&&s1[i]==s3[i+j]){
            check|=solve(i+1,j,s1,s2,s3,dp);
        }
        if(j<m&&s2[j]==s3[i+j]){
            check|=solve(i,j+1,s1,s2,s3,dp);
        }
        return dp[i][j]= check;
    }
    bool isInterleave(string s1, string s2, string s3) {
      n = s1.size();
      m = s2.size();
      string val = "";
      if(n+m!=s3.size()) return false;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
      return solve(0,0,s1,s2,s3,dp);  
    }
};