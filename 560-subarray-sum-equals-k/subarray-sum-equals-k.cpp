class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       // prev sabhi subarray sum ko hashset me store karo then check
       int n = nums.size();
       unordered_map<int,int> mp;
       mp[0]++;
       int ans =0;
       int val = 0;
       for(auto it:nums){
        val+=it;
        if(mp.find(val-k)!=mp.end()){
            ans+=mp[val-k];
        }
        mp[val]++;
       }
       return ans;
    }
};