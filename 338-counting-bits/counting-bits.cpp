class Solution {
public:
    vector<int> countBits(int n) {
     vector<int> ans(n+1,0);
    for(int i=1;i<=n;i++){
        int cnt=0;
        int val =i;
        while(val){
            if(val&1) cnt++;
            val = val>>1;
        }
        ans[i] = cnt;
    }
    return ans;
    }
};