class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
          unordered_map<int,vector<int>> mp;
        vector<int> indeg(numCourses,0);
        for(auto it:pre){
            mp[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
           if(indeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int val = q.front();
            q.pop();
            ans.push_back(val);
            for(auto it:mp[val]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        vector<int> store;
        return ans.size()==numCourses?ans:store;
    }
};