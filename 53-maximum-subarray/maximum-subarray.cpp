class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int ans = INT_MIN;
        for(auto it:nums){
            prev = max(prev+it,it);
            ans = max(ans,prev);
        }
        return ans;
    }
};