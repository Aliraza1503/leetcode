class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // directed acyclic graph for topological sorting 
        // mine approach for that problem store that has indegree zero and all upcoming branches
        unordered_map<int,vector<int>> mp;
        vector<int> indeg(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                mp[it].push_back(i);
                indeg[i]++;
            }
        }
            queue<int> q;
            vector<int> ans;
            for(int i=0;i<indeg.size();i++){
                if(indeg[i]==0){
                    q.push(i);
                }
            }
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
            }
    sort(ans.begin(),ans.end());
    return ans;
    }
};