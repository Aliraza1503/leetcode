class Solution {
public:
    // int gcd(int x,int y){
    //     int ans =1;
    //     for(int i=1;i<=min(x,y);i++){
    //         if(x%i==0&&y%i==0){
    //             ans = i;
    //         }
    //     }
    //     return ans;
    // }
    bool canMeasureWater(int x, int y, int target) {
        //condition if x+y<target return false;
        // find gcd of x and y and check is it divide the target or not
        if(x+y<target) return false;
        return target%gcd(x,y)==0;
    }
};