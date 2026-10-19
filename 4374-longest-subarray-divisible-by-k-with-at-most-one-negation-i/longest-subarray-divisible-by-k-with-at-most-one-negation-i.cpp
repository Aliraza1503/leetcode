class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0;
        for(int l=0;l<n;l++){
           long long sum =0;
           unordered_map<int,int>mp;
           for(int r =l;r<n;r++){
            sum+=nums[r];
            int x = (2LL*nums[r])%k;
            if(x<0) x+=k;
            mp[x]++;
            int rem = ((sum%k)+k)%k;
            if(rem==0||mp.count(rem)>=1){
                ans= max(ans,r-l+1);
            }
           }
        }
        return ans;
    }
};