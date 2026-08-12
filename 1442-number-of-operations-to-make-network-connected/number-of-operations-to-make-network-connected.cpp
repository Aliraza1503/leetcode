class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void unio(int x,int y){
        int x_parent = find(x);
        int y_parent= find(y);
        if(x_parent==y_parent) return;
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else {
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }

    }
    int makeConnected(int n, vector<vector<int>>& con) {
        int m = con.size();
        int val = n;
        if(n-m>1) return -1;
        parent.resize(n);
        rank.resize(n,0);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }
        
            for(auto it:con){
                int x_val = find(it[0]);
                int y_val = find(it[1]);
                if(x_val==y_val){
    
                }
                else {
                    unio(it[0],it[1]);
                    val--;
                }
        }
        return val-1;


    }
};