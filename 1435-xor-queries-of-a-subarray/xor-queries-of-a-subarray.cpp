class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // cant brute force here it will give tle for sure 
        // let run brute force here then we will optimize it 
        // vector<int> store;
        // int n = arr.size();
        // int m = queries.size();
        // for(int i=0;i<m;i++){
        //         int left = queries[i][0];
        //         int right= queries[i][1];
        //         int val =0;
        //         for(int j=left;j<=right;j++){
        //             val^=arr[j];
        //         }
        //         store.push_back(val);
        // }
        // return store;
        //optimize it
        // using prefix concept we will store in prefix array of size N+1 for right part and for left part it get automatically cancel out of xor
        int n = arr.size();
        vector<int> pref(n+1,0);
        for(int i=1;i<n+1;i++){
            pref[i]=pref[i-1]^arr[i-1];
        }
       
        n = queries.size();
         vector<int> store(n);
        for(int i=0;i<n;i++){
            int left = queries[i][0];
            int right = queries[i][1];
            store[i]=pref[right+1]^pref[left];
        }
        return store;

    }
};