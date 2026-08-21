
        class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else {
                int j =0;
                while(j<ans.size()&&ans[j]<nums[i]){
                    j++;
                }
                ans[j]=nums[i];
            }
        }
    return ans.size();
    }
};

