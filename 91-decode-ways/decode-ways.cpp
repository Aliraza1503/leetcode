class Solution {
public:
    int n;
    int dp[101];
    int solve(int i,string&s){
         if(s[i]=='0') return 0;
        if(i>=n-1) return 1;
       
        if(dp[i]!=-1) return dp[i];
        int take1 = solve(i+1,s);
        int take2 =0;
        if(i<n-1&&(s[i]=='1'&&(s[i+1]>='0'&&s[i+1]<='9'))||(i<n-1&&(s[i]=='2'&&(s[i+1]>='0'&&s[i+1]<='6')))){
            take2 = solve(i+2,s);
        }
        return dp[i]= take1+take2;

        
        
    }
    int numDecodings(string s) {
    n = s.size();
    if(s[0]=='0') return 0;
    memset(dp,-1,sizeof(dp));
    return solve(0,s);
    }
};