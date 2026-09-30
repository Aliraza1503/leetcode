class Solution {
public:
    int n;
    int dp[501][501];
    int solve(int i,int j,vector<int>&nums){
        if(i==j) return 0;
        int sum = 0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int p=i;p<=j;p++){
            sum+=nums[p];
        }
        int result =0;
        int cursum =0;
        for(int p=i;p<=j;p++){
            cursum+=nums[p];
            if(cursum<(sum-cursum)){
                // int val=cursum+solve(i,p,nums);
                result = max(result,cursum+solve(i,p,nums));
            }
            else if(cursum==sum-cursum){
                    // int val = cursum+max(solve(i,p,nums),solve(p+1,j,nums));
                    result = max(result,cursum+max(solve(i,p,nums),solve(p+1,j,nums)));
            }
            else{
                // int val = (sum-cursum)+solve(p+1,j,nums);
                result = max(result, (sum-cursum)+solve(p+1,j,nums));
            }
        }
        return dp[i][j]= result;

    }
    int stoneGameV(vector<int>& stoneValue) {
         n= stoneValue.size();
         memset(dp,-1,sizeof(dp));
        return solve(0,n-1,stoneValue);
    }
};