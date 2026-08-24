class Solution {
public:
    int minBitFlips(int start, int goal) {
       int store = start^goal;
       int count =0;
        for(int i=0;i<32;i++){
            int temp =1<<i;
            if(temp&store) count++;
        }
        return count;
    }
};