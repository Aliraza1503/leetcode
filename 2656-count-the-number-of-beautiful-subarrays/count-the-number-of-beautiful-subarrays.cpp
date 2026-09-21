class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        // one observation xor elements of array if it become zero add to the count 
        unordered_map<int,int> mp;
        mp[0]++;
        int val =0;
        long long ans =0;
        for(auto it:nums){
            val^=it;
            if(mp.find(val)!=mp.end()){
                    ans+=mp[val];
            }
            mp[val]++;
        }
        return ans;
    }
};