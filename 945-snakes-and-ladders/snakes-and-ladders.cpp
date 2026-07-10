class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int,int> adj;
       int count =0;
        for(int i =n-1;i>=0;i--){
            count++;
            for(int j =0;j<n;j++){
                if(board[i][j]!=-1){
                    if(count%2!=0){
                        int val = (n-(i+1))*(n)+(j+1);
                        adj[val]=board[i][j];
                    }
                    else {
                        int val = (n-(i+1))*(n)+(n-j);
                        adj[val]=board[i][j];
                    }
                }
            }
        }
        queue<pair<int,int>> q;
        q.push({1,0});
        vector<int> vis(n*n+1,0);
        vis[1]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
           int val = it.first;
           int freq = it.second;
           if(val==n*n) {return freq;}
           for(int i=val+1;i<=min(val+6,n*n);i++){
            int next = adj.count(i)?adj[i]:i;
            if(!vis[next]){
                vis[next]=1;
                q.push({next,freq+1});
            }
           }

        }
        return -1;
    }
};