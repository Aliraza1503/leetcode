class Solution {
public:
    int n;
    bool ispalindrome(int idx,int i,string&s){
        if(idx>=i){
            return true;
        }
        if(s[i]==s[idx]){
            return ispalindrome(idx+1,i-1,s);
        }
        return false;
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
        backtrack(0,s,store,ans);
        return ans;
    }
};