class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    int m = edges.size();
    unordered_map<int,vector<pair<int,double>>> adj;
    priority_queue<pair<double,int>,vector<pair<double,int>>> pq;
    for(int i =0;i<m;i++){
        int src = edges[i][0];
        int dest = edges[i][1];
        double val = succProb[i];
        adj[src].push_back({dest,val});
        adj[dest].push_back({src,val});
    }
    vector<double> store(n+1,0);
    pq.push({1,start_node});
    while(!pq.empty()){
        double prob = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int adjnode = it.first;
            double wt = it.second;
            if(prob*wt>store[adjnode]){
                store[adjnode]=prob*wt;
                pq.push({prob*wt,adjnode});
            }
        }
    }
    return store[end_node];
    }
};