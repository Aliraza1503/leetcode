class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int prmax = nums[0];
        int prmin = nums[0];
        for(int i=1;i<nums.size();i++){
            prmax = max(prmax+nums[i],nums[i]);
            prmin = min(prmin+nums[i],nums[i]);
            maxi = max(maxi,prmax);
            mini = min(mini,prmin);
        }
        return max(maxi,abs(mini));
    }
};