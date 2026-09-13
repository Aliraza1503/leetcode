class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        /*
        first approach at least one element i can skip
        second approach first left to right then left back to right back
        third approach take sum of all then find min subarray then subtract it might get done
        */
        // int ans = INT_MIN;
        // int prev = 0;
        // for(auto it:nums){
        //     prev = max(prev+it,it);
        //     ans = max(ans,prev);
        // }
        // prev = nums[0];
        // for(int i=nums.size()-1;i>=1;i--){
        //     prev = max(prev+nums[i],nums[i]);
        //     ans = max(ans,prev);
        // }
        // return ans;
        int totalsum = 0;
        for(auto it:nums){
            totalsum+=it;
        }
        int kadsum = nums[0];
        int kadsummin = nums[0];
        int prevmax = nums[0];
        int prevmin = nums[0];
        for(int i=1;i<nums.size();i++){
            int it = nums[i];
            prevmax = max(prevmax+it,it);
            prevmin = min(prevmin+it,it);
            kadsum=max(kadsum,prevmax);
            kadsummin = min(kadsummin,prevmin);

        }
            if(kadsum>0)
            return max(kadsum,totalsum-kadsummin);
            return kadsum;
        
    }
};