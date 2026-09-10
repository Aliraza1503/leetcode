class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int left = newInterval[0];
        int right = newInterval[1];
      int i =0;
      while(i<n&&intervals[i][1]<left){
        ans.push_back(intervals[i]);
        i++;
      }
      while(i<n&&intervals[i][0]<=right){
        left = min(left,intervals[i][0]);
        right = max(right,intervals[i][1]);
        i++;
      }
      ans.push_back({left,right});
      while(i<n){
        ans.push_back(intervals[i]);
        i++;
      }
      
        return ans;
    }
};