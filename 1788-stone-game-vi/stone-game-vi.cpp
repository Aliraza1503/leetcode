class Solution {
public:
    int n;
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        n = aliceValues.size();
        vector<vector<int>> store(n,vector<int>(2));
        for(int i=0;i<n;i++){
            store[i][0]=aliceValues[i]+bobValues[i];
            store[i][1]=i;
        }
        sort(store.rbegin(),store.rend());
        int alice =0;
        int bob =0;
        for(int i=0;i<n;i++){
            int idx = store[i][1];
          i%2==0?alice+=aliceValues[idx]:bob+=bobValues[idx];
        }
    
        if(alice>bob) return 1;
        if(alice==bob) return 0;
        return -1;
    }
};