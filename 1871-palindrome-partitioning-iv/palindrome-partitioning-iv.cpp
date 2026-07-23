class Solution {
public:
    bool checkPartitioning(string s) {
       int n = s.size();
       vector<vector<int>> st(n,vector<int>(n,0));
       for(int i = n-1;i>=0;i--){
        for(int j =i;j<n;j++){
            if(s[i]==s[j]){
                if(j-i<=2){
                    st[i][j]=true;
                }
                else {
                    st[i][j]=st[i+1][j-1];
                }
            }
        }
       }
        for(int i =0;i<n-2;i++){
            for(int j =i+1;j<n-1;j++){
                if(st[0][i]==1&&st[i+1][j]==1&&st[j+1][n-1]==1){
                    return true;
                }
            }
        }
        return false;
    }
};