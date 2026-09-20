class Solution {
public:
    int gd(int x,int y){
        int ans =0;
        for(int i=1;i<=min(x,y);i++){
            if(x%i==0&&y%i==0){
                ans =i;
            }
        }
        return ans;
    }
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target) return false;
        return target%gd(x,y)==0;
    }
};