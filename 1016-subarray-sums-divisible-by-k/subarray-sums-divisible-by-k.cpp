class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans =0;
        int val =0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(auto it:nums){
            val+=it;
            int rem = val%k;
            if(rem<0) rem+=k;
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};