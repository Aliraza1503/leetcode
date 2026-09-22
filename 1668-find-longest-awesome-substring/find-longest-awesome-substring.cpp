class Solution {
public:
    int longestAwesome(string s) {
        //
        int n = s.size();
       unordered_map<int,int>mp;
       mp[0]=-1;
       int x =0;
        int ans =0;
       for(int i=0;i<n;i++){
        int val = s[i]-'0';
        x = x^(1<<val);
        if(mp.find(x)!=mp.end()){
            int temp = i-mp[x];
             ans = max(ans,temp);
        }
        else{
            mp[x]=i;
        }
        for(int j =0;j<=9;j++){
            int fuck = x^(1<<j);
             if(mp.find(fuck)!=mp.end()){
                ans = max(ans,i-mp[fuck]);
             }
        }
       }
        return ans;
      }
};