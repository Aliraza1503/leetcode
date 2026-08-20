class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();
            vector<int> leftmin(n);
            vector<int> rightmin(n);
        
            int i =0;
            int j =0;
            while(i<n&&j<m){
                if(skill[i]==station[j]){
                    leftmin[i]=j;
                    i++;
                }
                j++;
            }
            i=n-1;
            j=m-1;

            while(i>=0&&j>=0){
                if(skill[i]==station[j]){
                    rightmin[i]=j;
                    i--;
                }
                j--;
            }
            int ans =0;
            for(int i =0;i<n;i++){
              int leftup = i<n-1?rightmin[i+1]-leftmin[i]:0;
              int rightdown = i>0?rightmin[i]-leftmin[i-1]:0;
              ans = max(ans,max(leftup,rightdown));
            }
            return ans;
    }
};