class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
       int n=nums.size();
        int base=0;
        map<pair<int,int>,int>mp;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                base++;
            }
            else{
                int a=min(nums[i],nums[i+1]);
                int b=max(nums[i],nums[i+1]);
                mp[{a,b}]++;
            }
        }
        int best=0;
        for(auto &p:mp){
            best=max(best,p.second);
        }
        return base+best;
    }
};