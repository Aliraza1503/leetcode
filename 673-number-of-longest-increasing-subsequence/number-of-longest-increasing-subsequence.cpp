class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n,1);
        vector<int> store(n,1);
        priority_queue<pair<int,int>> max_pq;
        for(int i =0;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(t[i]<1+t[j]){
                        t[i]=t[j]+1;
                        store[i]=store[j];
                    }
                    else if(t[j]+1==t[i]){
                        store[i]+=store[j];
                    }
                }
            }
        }
        int val = 0;
        for(auto it:t){
        val = max(it,val);
        }
        int ans = 0;
        for(int i =0;i<n;i++){
            if(t[i]==val){
                ans+=store[i];
            }
        }
        return ans;
    }
};