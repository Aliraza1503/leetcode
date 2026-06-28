class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int solve(int i,int j,string&s1,string&s2){
        if(i>=n){
            int sum =0;
            for(int k = j;k<m;k++){
                sum+=s2[k];
            }
            return sum;
        }
          if(j>=m){
            int sum =0;
            for(int k = i;k<n;k++){
                sum+=s1[k];
            }
            return sum;
          }
          if(dp[i][j]!=-1) return dp[i][j];
        int equal = 1e5;
        int skipleft = 1e5;
        int skipright = 1e5;
        if(s1[i]==s2[j]){
            equal = solve(i+1,j+1,s1,s2);
        }
        skipleft = s1[i]+solve(i+1,j,s1,s2);
        skipright = s2[j]+solve(i,j+1,s1,s2);
        return dp[i][j]= min(equal,min(skipleft,skipright));

          }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2);
    }
};