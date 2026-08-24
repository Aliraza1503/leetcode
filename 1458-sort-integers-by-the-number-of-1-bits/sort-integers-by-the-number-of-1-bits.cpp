class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> freq;
        for(auto it:arr){
            int count =0;
            for(int k=0;k<=31;k++){
                int temp = (1<<k);
                if(it&temp) count++;
            }
            freq[count].push_back(it);
        }
        vector<int> ans;
        for(int i=0;i<=32;i++){
            vector<int>check = freq[i];
            sort(check.begin(),check.end());
            for(auto it:check){
                ans.push_back(it);
            }
        }
        return ans;
    }
};