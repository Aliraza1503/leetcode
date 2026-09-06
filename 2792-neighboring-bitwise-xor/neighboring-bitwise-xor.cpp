class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {

        vector<int>nums;

        //case 1
       
int ans =0;
for(auto it:d){
    ans^=it;
}
return ans==0;

        
    }
};