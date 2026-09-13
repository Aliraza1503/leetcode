class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int mini = INT_MAX;
        for(auto it:prices){
            mini = min(mini,it);
            ans = max({0,ans,it-mini});
        }
        return ans;
    }
};