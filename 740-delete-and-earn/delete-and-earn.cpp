class Solution {
public:
    int n;
    int dp[20001];
    int solve(int i,vector<int>&store,unordered_map<int,int>&mp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
    int idx = n;
        if(i+1<n){
            idx = (store[i+1]-store[i])==1?idx = i+2:idx = i+1;
        }
        int take = store[i]*mp[store[i]]+solve(idx,store,mp);
        int ntake = solve(i+1,store,mp);
        return dp[i]= max(take,ntake);

    }
    int deleteAndEarn(vector<int>& nums) {
        /*
        1store in map 
        2 new vector store non duplicates then sort
        2 3 4 

        */
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<int> store;
        for(auto it:mp){
            store.push_back(it.first);
        }
        sort(store.begin(),store.end());
        n = store.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,store,mp);
    }
};