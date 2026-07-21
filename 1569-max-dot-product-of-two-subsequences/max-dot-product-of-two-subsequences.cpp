class Solution {
public:
    int n,m;
   
    int solve(int i,int j,vector<int>&nums1,vector<int>&nums2, vector<vector<int>>& dp){
        if(i>=n||j>=m) return -1e9;
        int take =INT_MIN;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        
        take = max(nums1[i]*nums2[j],nums1[i]*nums2[j]+solve(i+1,j+1,nums1,nums2,dp));
        int nleft = solve(i+1,j,nums1,nums2,dp);
        int nright =solve(i,j+1,nums1,nums2,dp);
        return dp[i][j]= max(take,max(nleft,nright));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));

        return solve(0,0,nums1,nums2,dp);
    }
};