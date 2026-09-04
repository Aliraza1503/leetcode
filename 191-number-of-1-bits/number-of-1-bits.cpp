class Solution {
public:
    int hammingWeight(int n) {
     
     int val =0;
   for(int i=31;i>=0;i--){
    if((n>>i)&1==1)val++;
   }
   return val;
    /*
    approach 2
    int val=0;
    while(n){
    n = n&(n-1);
    val++;
    }
    return val;
    */
    }
};