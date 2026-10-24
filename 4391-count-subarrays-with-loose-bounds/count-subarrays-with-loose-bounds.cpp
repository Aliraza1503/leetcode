class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
     int n = nums.size();
        long long ans =0;
        int len =0;
        for(auto it:nums){
            if(it>=minK&&it<=maxK){
                len++;
                ans+=len;
            }
            else{
                len =0;
            }
        }
        
        return ans;
    }
};