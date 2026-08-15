class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
     bool unio(int x,int y){
        int x1 = find(x);
        int y1 = find(y);
        if(x1==y1) return true;
        if(rank[x1]>rank[y1]){
            parent[y1]=x1;
        }
        else if(rank[x1]<rank[y1]){
            parent[x1]=y1;
        }
        else {
            parent[x1]=y1;
            rank[y1]++;
        }
        return false;
    }
    int removeStones(vector<vector<int>>& stones) {
        //think like connected component problem
        int n  =stones.size();
      
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int comp = n;
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if((stones[i][0]==stones[j][0])||stones[i][1]==stones[j][1]){
                    if(unio(i,j)==false){
                        comp--;
                    }
                }
            }
        }
        return n-comp;
    }
};

/*
    21  22 

10      12

00  01




20    22
   11
00    02
*/