class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(int i,int j,vector<int>&nums1,vector<int>&nums2){
        if(i>=n||j>=m) return 0;
        int take =0;
        int nleft = 0;
        int nright = 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]){
            int p = max(i,j);
            take = 1+solve(i+1,j+1,nums1,nums2);
        }
             nleft = solve(i+1,j,nums1,nums2);
            nright = solve(i,j+1,nums1,nums2);
        return dp[i][j]= max(take,max(nleft,nright));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    n = nums1.size();
    m = nums2.size();
    memset(dp,-1,sizeof(dp));
    return solve(0,0,nums1,nums2);
       
    }
};