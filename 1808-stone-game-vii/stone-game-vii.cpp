class Solution {
public:
    int n;
    int dp[1001][1001][2];
    int solve(int i,int j,int check,vector<int>&nums){
        if(i==j) return 0;
        int sum =0;
        if(dp[i][j][check]!=-1) return dp[i][j][check];
        for(int idx =i;idx<=j;idx++){
            sum+=nums[idx];
        }
          int ans =0;
       
        
        if(check==0){
            int takeleft = (sum-nums[i])+solve(i+1,j,1,nums);
            int takeright = (sum-nums[j])+solve(i,j-1,1,nums);
            ans = max(takeleft,takeright);
        }
        else{
          int takeleft = solve(i+1,j,0,nums)-(sum-nums[i]);
          int takeright = solve(i,j-1,0,nums)-(sum-nums[j]);
            ans =min(takeleft,takeright);
        }
        return dp[i][j][check]= ans;

    }
    int stoneGameVII(vector<int>& stones) {
        n = stones.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,0,stones);
    }
};