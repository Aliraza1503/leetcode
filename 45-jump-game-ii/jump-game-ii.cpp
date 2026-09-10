class Solution {
public:
    int n;
    int dp[10001];
    int solve(int i,vector<int>&nums){
        if(i>=n-1) return 0;
        int val = nums[i];
        int res = 1e5;
        if(dp[i]!=-1) return dp[i];
        for(int j =1;j<=min(val,n-1-i);j++){
            int temp = 1+solve(i+j,nums);
            res = min(res,temp);
        }
        return dp[i]= res;
        
    }
    int jump(vector<int>& nums) {
        //lets take dp solution 
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};