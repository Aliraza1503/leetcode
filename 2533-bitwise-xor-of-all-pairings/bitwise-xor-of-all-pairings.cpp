class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
  
      int n1 = nums1.size();
      int n2 = nums2.size();
        if(n1%2==0&&n2%2==0) return 0;
        if(n1%2==0) {
            int val=0;
            for(auto it:nums1){
                val^=it;
            }
            return val;
        }
         if(n2%2==0) {
            int val=0;
            for(auto it:nums2){
                val^=it;
            }
            return val;
        }
        int val1=0;
        for(auto it:nums1){
            val1^=it;
        }
        for(auto it:nums2){
            val1^=it;
        }
        return val1;
    }
};