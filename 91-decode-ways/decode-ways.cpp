class Solution {
public:
    int n;
    int numDecodings(string s) {
    n = s.size();
    // if(s[0]=='0') return 0;
    // memset(dp,-1,sizeof(dp));
    // return solve(0,s);
    vector<int> dp(n+1);
    dp[n]=1;
    for(int i =n-1;i>=0;i--){
        if(s[i]=='0'){
            dp[i]=0;
        }
        else {
            dp[i]=dp[i+1];
            if(i<n-1&&(s[i]=='1'||(s[i]=='2'&&s[i+1]>='0'&&s[i+1]<='6'))){
                dp[i]+=dp[i+2];
            }
        }
    }
    return dp[0];
    }
};