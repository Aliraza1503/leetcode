class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            int mask =1;
            int cnt=0;
            for(int j=0;j<31;j++){
                int check = (i&mask)!=0;
                cnt+=check;
                mask<<=1;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};