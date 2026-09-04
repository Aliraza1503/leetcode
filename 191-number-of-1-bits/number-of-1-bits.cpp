class Solution {
public:
    int hammingWeight(int n) {
     
    //  approach 1
//      int val =0;
//    for(int i=31;i>=0;i--){
//     if((n>>i)&1==1)val++;
//    }
//    return val;
    /*
    approach 2
    int val=0;
    while(n){
    n = n&(n-1);
    val++;
    }
    return val;
    */
    // using rightshift
    // int val =0;
    // while(n>0){
    //     if(n&1) val++;
    //     n = n>>1;
    // }
    // return val;

    // using leftshift;
    int ans =0;
    for(int i=0;i<32;i++){
        int temp = 1<<i;
        if(temp&n) ans++;
    }
    return ans;

    }
};