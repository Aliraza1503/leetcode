class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>nums(n);
        nums[0]=stones[0];
        for(int i=1;i<n;i++){
            nums[i]=nums[i-1]+stones[i];
        }
        int ans =nums[n-1];
        for(int i=n-2;i>=1;i--){
            ans =max(ans,nums[i]-ans);
        }
        return ans;
    }
};