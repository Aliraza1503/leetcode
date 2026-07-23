class Solution {
public:
    int n;
    int dp[17][17];
    bool ispalindrome(int idx,int i,string&s){
        if(idx>=i){
            return true;
        }
        if(dp[idx][i]!=-1) return dp[idx][i];
        if(s[i]==s[idx]){
            return dp[idx][i]= ispalindrome(idx+1,i-1,s);
        }
        return dp[idx][i]= false;
    }
    void backtrack(int idx,string&s,vector<string>&store,vector<vector<string>>&ans){
        if(idx==n){
            ans.push_back(store);
            return ;
        }
        for(int i =idx;i<n;i++){
            if(ispalindrome(idx,i,s)){
                store.push_back(s.substr(idx,i-idx+1));
                backtrack(i+1,s,store,ans);
                store.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> store;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        backtrack(0,s,store,ans);
        return ans;
    }
};