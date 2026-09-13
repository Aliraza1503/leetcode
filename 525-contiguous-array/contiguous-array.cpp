class Solution {
public:
    int findMaxLength(vector<int>& nums) {
     //you cannot do that like storing no of ones and then no of zeros and return 2*min of two 
     unordered_map<int,int> mp;
     mp[0]=-1;
     vector<int> store;
     for(auto it:nums){
        it==0?store.push_back(-1):store.push_back(1);
     }
     int sum =0;
     int ans =0;
     for(int i=0;i<nums.size();i++){
        sum+=store[i];
        if(mp.find(sum)!=mp.end()){
            ans = max(ans,i-mp[sum]);
        }
        else{
            mp[sum]=i;
        }

     }
        return ans;
       
    }
};