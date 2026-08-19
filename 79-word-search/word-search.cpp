class Solution {
public:
    vector<int> row = {-1,0,1,0};
    vector<int> col = {0,-1,0,1};
    int n,m;
    int p;
    void dfs(int i,int j,int idx,vector<vector<char>>&board,string&word,bool& check,vector<vector<int>>&vis){
        
        idx++;
        vis[i][j]=1;
        if(idx==p) {
            check = true;
            return;
        }
    
        for(int r = 0;r<4;r++){
            int i1 = i+row[r];
            int j1 = j+col[r];
            if(i1>=0&&i1<n&&j1>=0&&j1<m&&board[i1][j1]==word[idx]&&vis[i1][j1]==0){
                dfs(i1,j1,idx,board,word,check,vis);
                //   if(check) return ;
            }
        }
       vis[i][j]=0;
    }
    bool exist(vector<vector<char>>& board, string word) {
         p= word.size();
            n = board.size();
         m = board[0].size();
        for(int i =0;i<board.size();i++){
            for(int j =0;j<m;j++){
                vector<vector<int>> vis(n,vector<int>(m,0));
                bool check = false;
                //pass by reference to the check 

            if(board[i][j]==word[0]){
                dfs(i,j,0,board,word,check,vis);
                if(check) return true;
            }
            }
        }
       return false;
    }
};