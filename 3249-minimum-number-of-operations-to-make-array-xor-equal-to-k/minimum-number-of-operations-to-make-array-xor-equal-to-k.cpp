class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans =0;
        for(auto it:nums){
            ans^=it;
        }
        int cnt =0;
        for(int i=0;i<32;i++){
            int temp = (1<<i);
            int fir = (temp&ans)!=0;
            int sec = (temp&k)!=0;
            cnt+=(fir!=sec);
            
        }
        return cnt;
    }
};