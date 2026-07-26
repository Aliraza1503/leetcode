class Solution {
public:
    int n;
    int dp[1001][2004];
    int solve(int i ,int prev,vector<vector<int>>&pairs){
        if(i>=n) return 0;
        int take =0;
        int check = prev+1001;
        if(dp[i][check]!=-1) return dp[i][check];
        if(pairs[i][0]>prev){
            take = 1 + solve(i+1,pairs[i][1],pairs);
        }
        int nottake = solve(i+1,prev,pairs);
        return dp[i][check]= max(take,nottake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
         n = pairs.size();
         sort(pairs.begin(),pairs.end());
         memset(dp,-1,sizeof(dp));
        return solve(0,-1001,pairs);
    }
};