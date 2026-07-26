class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int val =INT_MIN;
        for(auto it:prices){
            mini = min(mini,it);
            val = max(val,it-mini);
        }
        return val;
    }
};