class Solution {
public:
    int hammingDistance(int x, int y) {
        int store = x^y;
        int count =0;
        for(int i=0;i<32;i++){
            int temp = 1<<i;
            if(temp&store) count++;
        }
        return count;
    }
};