class Solution {
public:
    unordered_map<int,int> mp;
    bool isvalid(vector<int>&nums,int r){
        for(auto it:mp){
            int fir =it.first;
            int sec =it.second;
            if(mp.count(fir+nums[r])){
               return false;
            }
            int other = nums[r]-fir;
            if(other>0&&mp.count(other)){
                if(fir!=other||sec>1){
                    return false;
            }
            }

        }
        return true;
    }
    int maxSubarray(vector<int>& nums) {
        int l=0,r=0;
        int n = nums.size();
        int ans =0;
        while(r<n){
            if(isvalid(nums,r)){
                mp[nums[r]]++;
                r++;
            }
            else{
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans = max(ans,r-l);
        }
        return ans;
    }
};