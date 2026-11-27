class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        //firstly i will solve it using bfs method which is also called as kahns algorithm
        unordered_map<int,vector<int>> mp;

        vector<int> indeg(num,0);
        for(auto it:pre){
            mp[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            ans.push_back(val);
            for(auto it:mp[val]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        };
        return ans.size()==num;
    }
};