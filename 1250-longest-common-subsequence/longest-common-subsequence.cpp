class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int solve(int i,int j,string&text1,string&text2){
        if(i>=n||j>=m) return 0;
        int take =0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            take = 1+solve(i+1,j+1,text1,text2);
        }
        int left = solve(i+1,j,text1,text2);
        int right = solve(i,j+1,text1,text2);
        return dp[i][j]= max(take,max(left,right));
    }
    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,text1,text2);
        vector<vector<int>> store(n+1,vector<int>(m+1));
        for(int i =0;i<n;i++){
            store[i][0]=0;
        }
        for(int j =0;j<m;j++){
            store[0][j]=0;
        }
        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]){
                    store[i][j]=1+store[i-1][j-1];
                }
                else{
                    store[i][j]=max(store[i-1][j],store[i][j-1]);
                }
            }
        }
        return store[n][m];
    }
};