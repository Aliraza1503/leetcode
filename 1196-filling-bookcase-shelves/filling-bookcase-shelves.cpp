class Solution {
public:
    int n;
    int dp[1001];
    int solve(int i,vector<vector<int>>&books,int val){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int height =0;
        int width =0;
        int ans = INT_MAX;
        for(int j=i;j<n;j++){
            width+=books[j][0];
            if(width>val) break;
            height = max(height,books[j][1]);
            int take = height + solve(j+1,books,val);
            ans = min(ans,take);
        }
        return dp[i]= ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,books,shelfWidth);
    }
};