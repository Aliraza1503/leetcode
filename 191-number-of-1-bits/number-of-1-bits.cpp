class Solution {
public:
    int hammingWeight(int n) {
     int val =0;
     while(n){
        n = n&(n-1);
        val++;
     }
     return val;
    }
};