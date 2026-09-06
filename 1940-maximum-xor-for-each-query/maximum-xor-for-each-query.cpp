class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int XOR =0;
        for(auto it:nums){
            XOR^=it;
        }
        int mask = ((1<<maximumBit)-1);
        vector<int> store;
        for(int i=0;i<nums.size();i++){
            store.push_back(mask^XOR);
            XOR^=nums[nums.size()-i-1];
        }
        return store;
    }
};