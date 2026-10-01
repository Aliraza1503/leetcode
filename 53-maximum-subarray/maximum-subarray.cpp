class Solution {
public:
    typedef long long ll;
    int maxSubArray(vector<int>& nums) {
        ll prefix =0;
        ll minpref =0;
        ll ans = LLONG_MIN;
        for(int x:nums){
            prefix+=x;
            ans = max(ans,prefix-minpref);
            minpref = min(minpref,prefix);
        }
        return ans;
    }
};