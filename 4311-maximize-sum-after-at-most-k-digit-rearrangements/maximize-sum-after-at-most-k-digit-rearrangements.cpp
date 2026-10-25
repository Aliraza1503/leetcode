class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long ans =0;
        int n= nums.size();
        priority_queue<pair<long long,int>>pq;
    
        for(int i=0;i<n;i++){
        auto it = nums[i];
        ans+=it;
            string s = to_string(it);
            sort(s.rbegin(),s.rend());
            long long val = stoll(s);
            pq.push({val-nums[i],i});
        }
        while(!pq.empty()&&k>0){
            auto [val,i] = pq.top();
            pq.pop();
        ans +=val;
        k--;

        }
        return ans;
    }
};