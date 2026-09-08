class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> mp;
        vector<int> indeg(num,0);
        for(auto it:pre){
            mp[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        queue<int> q;
        for(int i=0;i<num;i++){
            if(indeg[i]==0)q.push(i);
        }
        // i have done a mistake there i just assume prev value will always be the prereq of next element 

        // unordered_map<int,int> store;
        // int freq =0;
        vector<vector<bool>> store(num,vector<bool>(num,false));
        while(!q.empty()){
            int prev = q.front();
            q.pop();   
           for(auto next:mp[prev]){
             store[prev][next]=true;
            for(int i=0;i<num;i++){
               if(store[i][prev]){
                store[i][next]=true;
               }
            }
            indeg[next]--;
            if(indeg[next]==0) {
                q.push(next);
            }
           }   
        }
        int n = queries.size();
        vector<bool> ans(n);
        for(int i=0;i<n;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i]=store[u][v];
        }
        return ans;
        
    }
};