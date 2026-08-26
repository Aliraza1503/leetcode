class Solution {
public:
 void check(vector<vector<int>>& ans, vector<int>& curr, int n, int k, int start) {
        if (k == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            check(ans, curr, n, k - 1, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
         vector<int> curr;
        vector<vector<int>> ans;

        check(ans, curr, n, k, 1);

        return ans;
    }
};