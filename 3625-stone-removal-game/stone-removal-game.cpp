class Solution {
public:
    bool canAliceWin(int n) {
        int cnt =0;
        int dec =10;
        while(n&&dec<=n){
            n-=dec;
            dec-=1;
            cnt++;
        }
        return cnt%2!=0;
    }
};