class Solution {
public:
    int n;
   int dp[21][10002];
    int solve(int i,int diff,vector<int>&nums){
        if(i>=n){
            if(diff==0){
                return 0;
            }
        return INT_MIN;
        }
        int temp = 5001+diff;
        if(dp[i][temp]!=-1) return dp[i][temp];
      
        int nothing = solve(i+1,diff,nums);
        int l1len =nums[i]+ solve(i+1,diff+nums[i],nums);
        int l2len = nums[i]+ solve(i+1,diff-nums[i],nums);
      return    dp[i][temp]= max({nothing,l1len,l2len});
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
            memset(dp,-1,sizeof(dp));
          return solve(0,0,rods)/2;

    }
};