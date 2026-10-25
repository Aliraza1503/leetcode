class Solution {
public:
    long long countStaircase(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> rank;
            int distinct = 0;
            int bad = 0;
            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (freq[x] == 0) {
                    distinct++;
                    rank[x] = distinct;
                    bad++;  
                }     
                if (freq[x] != rank[x]) {
                    bad--;
                }
             freq[x]++;
                if (freq[x] != rank[x]) {
                    bad++;
                }
                if (bad == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};