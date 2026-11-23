class Solution {
public:
    int n;
    void solve(int node,vector<int> store,vector<vector<int>>&graph,vector<vector<int>>&ans){
        for(auto it:graph[node]){
            store.push_back(it);
            if(it==n-1){
                ans.push_back(store);
            }
            else{
                solve(it,store,graph,ans);
            }
            store.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         n = graph.size();
        vector<vector<int>> ans;
        vector<int> store;
        store.push_back(0);
        solve(0,store,graph,ans);
        return ans;
    }
};