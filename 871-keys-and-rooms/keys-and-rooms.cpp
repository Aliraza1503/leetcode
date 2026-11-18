class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int val = q.front();
            vis[val]=1;
            q.pop();
            for(auto it:rooms[val]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        for(auto it:vis){
            if(it==0) return false;
        }
        return true;
    }
};