class Solution {
public:
    int trailingZeroes(int n) {
        // this question hints how many 5s there are in n
        int ans =0;
        for(int i=5;i<=n;i*=5){
            int temp = n;
                int cnt = (temp/i);
                ans+=cnt;
        }
        return ans;
    }
};