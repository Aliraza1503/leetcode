class Solution {
public:
    int rob(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp1(n+2,0);
        vector<int> dp2(n+2,0);
        for(int i =n-2;i>=0;i--){
            dp1[i]=max(dp1[i+1],cost[i]+dp1[i+2]);
        }
        for(int i =n-1;i>0;i--){
            dp2[i]=max(dp2[i+1],cost[i]+dp2[i+2]);
        }
        return n==1?cost[0]:max(dp1[0],dp2[1]);
    }
};