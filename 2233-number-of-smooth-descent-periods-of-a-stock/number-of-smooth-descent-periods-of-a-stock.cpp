class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n =prices.size();
        long long val = n;
        long long check =prices[0];
        long long tot =0;
        for(int i =1;i<n;i++){
            if(check-prices[i]==1){
               check=prices[i];
                val+=1;
                val+=tot;
                tot++;
            
            }
            else{
                tot =0;
                check=prices[i];
            }
        }
        return val;
    }
};