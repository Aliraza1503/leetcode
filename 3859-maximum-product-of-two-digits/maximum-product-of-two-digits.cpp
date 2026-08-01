class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0;
        int max2 =0;
        while(n){
            if(max1<n%10){
                max2 = max1;
                max1 = n%10;
            }
            else if(max2<n%10){
                max2 = n%10;
            }
            n/=10;
        }
        return max1*max2;
    }
};