class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int x= i;
            int count =0;
            for(int k=0;k<=31;k++){
                int temp = (1<<k);
                if(temp&x)count++;
                
            }
            ans.push_back(count);
        }
        return ans;
    }
};