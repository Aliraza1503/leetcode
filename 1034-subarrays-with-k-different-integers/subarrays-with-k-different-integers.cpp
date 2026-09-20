class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        /*
        step 1 sliding window for len<=k 
        step 2 sliding window for len<=k-1
        */
        int n= nums.size();
        int l =0;
        int r =0;
        int count =0;
        unordered_map<int,int> mp;
        while(r<n&&l<=r){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
           mp.erase(nums[l]);
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        unordered_map<int,int> mpp;
        int tot =0;
        l=0;
        r=0;
            while(r<n&&l<=r){
            mpp[nums[r]]++;
            while(mpp.size()>k-1){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            tot+=(r-l+1);
            r++;
        }
        return count-tot;
    }
};