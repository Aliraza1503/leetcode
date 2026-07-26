class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) {
        int n = en.size();
        sort(en.begin(),en.end(),[](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<int> temp;
        temp.push_back(en[0][1]);
       for(int i =0;i<n;i++){
        if(en[i][1]>temp.back()){
            temp.push_back(en[i][1]);
        }
        else {
            int left =0;
            int right =temp.size()-1;
            int val = en[i][1];
         
            while(left<right){
                int mid = (left+right)/2;
                if(temp[mid]>=val){
                    right =mid;
                }
                else {
                    left = mid+1;
                  
                }
            }
            temp[left]=val;
        }
       }
       return temp.size();
    }
};