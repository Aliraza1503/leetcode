class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
       //length of longest subarray and sum has to be k length must be greater than or equal 
       // to 2 
       unordered_map<int,int> mp;
       mp[0]=-1;
       int ans =0;
       int val =0;
       for(int i=0;i<nums.size();i++){
        int it = nums[i];
        val+=it;
        int rem = val%k;
        if(rem<0) rem+=k;
        if(mp.find(rem)!=mp.end()){
            ans = max(ans,i-mp[rem]);
            if(ans>=2) return true;
        }
       else{ 
         mp[rem]=i;
       }
       }
       return false;
    }
};