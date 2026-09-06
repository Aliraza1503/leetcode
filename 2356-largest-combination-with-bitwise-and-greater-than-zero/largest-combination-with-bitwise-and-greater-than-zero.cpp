class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        // 1610000
        //17 10001
     //62  0111110
     //24    11000 and of all this will be 1 

     // approach 1 run a for loop for 32 times and iterate in whole loop 
     int ans =0;
     for(int i=0;i<32;i++){
        int val =0;
        for(auto it:candidates){
            if(it&(1<<i)) val++;
        }
             ans = max(val,ans);
     }
     return ans;
    }
};