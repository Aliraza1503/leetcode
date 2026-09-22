class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> store(5,0);
        string check = "00000";
        unordered_map<string,int> mp;
        mp[check]=-1;
        int ans = 0;
        for(int i=0;i<n;i++){
            auto it = s[i];
                if(it=='a'){
                    store[0]=(store[0]+1)%2;
                }
                else if(it=='e'){
                    store[1]=(store[1]+1)%2;
                }
                else if(it=='i'){
                    store[2]=(store[2]+1)%2;
                }
                else if(it=='o'){
                    store[3]=(store[3]+1)%2;
                }
                else if(it=='u'){
                    store[4]=(store[4]+1)%2;
                }
                string temp = "";
                for(auto val:store){
                        temp+=to_string(val);
                }
                if(mp.find(temp)!=mp.end()){
                    ans = max(ans,i-mp[temp]);
                }
                else{
                mp[temp]=i;
                }
        }
        return ans;
    }
};