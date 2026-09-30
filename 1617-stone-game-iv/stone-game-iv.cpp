class Solution {
public:
    int dp[100001];
    bool solve(int n){
        if(n==0) return false;
        if(dp[n]!=-1) return dp[n];
        for(int val =1;val*val<=n;val++){
            if(solve(n-val*val)==false) return dp[n]= true;
        }
        return dp[n]= false;
    }
    bool winnerSquareGame(int n) {
      //check the conditions 
       // if 1 alice wins 
       /*
       */ 
        // memset(dp,-1,sizeof(dp));
    //   return solve(n);
    vector<bool> store(n+1,false);
    for(int i=0;i<n+1;i++){
        for(int val =1;val*val<=i;val++){
            if(store[i-val*val]==false){
                store[i]=true;
                break;
            }
        }
    }
     return store[n]==true;
    }
};