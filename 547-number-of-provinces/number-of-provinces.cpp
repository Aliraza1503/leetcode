class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    int unio(int x,int y){
        int xp = find(x);
        int yp = find(y);
        if(xp==yp) return 1;
        if(rank[xp]>rank[yp]){
            parent[yp]=xp;
        }
        else if(rank[xp]<rank[yp]){
            parent[xp]=yp;
        }
        else{
            parent[xp]=yp;
            rank[yp]++;
        }
        return 0;
    }
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<int,vector<int>> adj;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(i!=j&&nums[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans =n;
        for(int i =0;i<n;i++){
            for(auto it:adj[i]){
                if(unio(i,it)==0){
                    ans--;
                }
            }
        }
        return ans;
    }
};