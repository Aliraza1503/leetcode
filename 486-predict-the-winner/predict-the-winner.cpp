class Solution {
public:
    int n;
    int dp[21][21][2];
    int solve(int i,int j,int person,vector<int>&nums){
        if(i>j) return 0;
        int val =0;
        if(dp[i][j][person]!=-1) return dp[i][j][person];
        person==1?val=0:val=INT_MAX;
        if(person==1){
            val +=max(nums[i]+solve(i+1,j,0,nums),nums[j]+solve(i,j-1,0,nums));
        }
        else{
            val = min(solve(i+1,j,1,nums),solve(i,j-1,1,nums));
        }
        return dp[i][j][person]= val;
    }
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        int ans =0;
        for(auto it:nums){
            ans+=it;
        }
        memset(dp,-1,sizeof(dp));
        if(ans%2!=0) return solve(0,n-1,1,nums)>=(ans/2)+1?true:false;
        return solve(0,n-1,1,nums)>=ans/2?true:false;
    }
};