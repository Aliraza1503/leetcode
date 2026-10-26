class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
          long long ans=0;
       int n=nums.size();
       vector<long long> store(n);
       for(int i=0;i<n;i++){
           ans+=nums[i];
           string s =to_string(nums[i]);
           sort(s.rbegin(),s.rend());
           long long val =stoll(s)-nums[i];
           store[i]=val;
       }
       sort(store.rbegin(),store.rend());
       for(int i=0;i<k;i++){
           ans+=store[i];
       }
       return ans;
    }
};