class Solution {
public:
    typedef long long ll;
    vector<int> singleNumber(vector<int>& nums) {
        ll temp =0;
        for(auto it:nums){
            temp^=it;
        }
         int rightmostbit1=temp&(-temp);
         int val1=0;
        int val2=0;
        for(auto it:nums){
            if(rightmostbit1&it){
                val1^=it;
            }
            else{
                val2^=it;
            }
        }
        return {val1,val2};
    }
};