class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n =nums.size();
        unordered_map<int,int>mp;
        int ans =0;
        int val =0;
        mp[0]=1;
        for(auto it:nums){
            val+=it;
            if(mp.find(val-goal)!=mp.end()){
                ans+=mp[val-goal];
            }
            mp[val]++;
        }
        return ans;
    }
};