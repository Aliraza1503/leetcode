class Solution {
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    int find(int x){
            if(parent[x]==x) return x;
            return parent[x]= find(parent[x]);
    }
    int unio(int x,int y){
        int x_parent=find(x);
        int y_parent = find(y);
        if(x_parent==y_parent) return 1;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
       else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
        return 0;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> mp;
        int n = isConnected.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&isConnected[i][j]==1){
                    mp[i].push_back(j);
                }
            }
        }
        int ans =n;
       for(int i =0;i<n;i++){
        for(auto it:mp[i]){
            if(unio(it,i)==0){
                ans--;
            }
        }
       }
       return ans;
    }
};