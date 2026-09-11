class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> store(n+2,0);
        for(int i=0;i<n;i++){
            store[i+2]=max(store[i+1],store[i]+nums[i]);
        }
        return store[n+1];
    }
};