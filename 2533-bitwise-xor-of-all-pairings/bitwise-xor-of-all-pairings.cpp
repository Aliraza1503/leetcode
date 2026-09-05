class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
  
      int n1 = nums1.size();
      int n2 = nums2.size();
      int val=0;
        if(n1%2==0&&n2%2==0) return 0;
       else if(n1%2==0) {
            for(auto it:nums1){
                val^=it;
            }
        }
       else  if(n2%2==0) {
            for(auto it:nums2){
                val^=it;
            }
        }
        else {
        for(auto it:nums1){
            val^=it;
        }
        for(auto it:nums2){
            val^=it;
        }
        }
        return val;
    }
};