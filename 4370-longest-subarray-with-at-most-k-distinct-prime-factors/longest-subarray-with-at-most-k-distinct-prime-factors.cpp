class Solution {
public:
    unordered_set<int> st;
    unordered_map<int,int>mp;
    unordered_map<int,vector<int>> store;
    void prime(int n,int val,unordered_map<int,vector<int>>& store){
        if(!store.count(val)){
        for(int i=2;i*i<=n;i++){
            if(n%i==0) {
                // mp[i]++;
                store[val].push_back(i);
                //  st.insert(i);
                 while(n%i==0){
                n/=i;
            }
            }
        }
        if(n>1) {
            // mp[n]++;
            //  st.insert(n);
            store[val].push_back(n);
        }
        }
          for (int p : store[val]) {
        mp[p]++;
        st.insert(p);
    }
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int j =0;
        int ans =0;
        for(int i=0;i<n;i++){
            prime(nums[i],nums[i],store);
            while(st.size()>k){
                for(auto it:store[nums[j]]){
                    mp[it]--;
                    if(mp[it]==0){
                    st.erase(it);
                    }
                }
                j++;
            }
        ans = max(ans,i-j+1);
        }
    return ans;
    }
};