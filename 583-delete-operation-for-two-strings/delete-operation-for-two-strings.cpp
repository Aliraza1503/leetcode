class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(int i,int j,string &w1,string & w2){
        if(i>=n||j>=m) return 0;
        int take = 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]){
            take = 1 + solve(i+1,j+1,w1,w2);
        }
        int left = solve(i+1,j,w1,w2);
        int right = solve(i,j+1,w1,w2);
        return dp[i][j]= max(take,max(left,right));
    }
    int minDistance(string w1, string w2) {
        n = w1.size();
        m = w2.size();
        memset(dp,-1,sizeof(dp));
        int val = solve(0,0,w1,w2);
        return n+m-2*val;
    }
};