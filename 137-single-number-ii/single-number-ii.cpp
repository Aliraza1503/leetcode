class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res =0;
        for(int k=0;k<=31;k++){
            int countzero = 0;
            int countone =0;
            int temp = (1<<k);
            for(auto num:nums){
                if((num&temp)==0) countzero++;
                else
                    countone++;
            }
            if(countone%3==1){
                res = res|temp;
            }
        }
        return res;
    }
};