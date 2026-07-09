class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        unordered_set<string> st;
        for(int i =0;i<n;i++){
            st.insert(deadends[i]);
        }
        if(target=="0000") return 0;
        unordered_set<string> vis;
        queue<pair<string,int>> q;
        q.push({"0000",0});
        string fir = "0000";
        vis.insert(fir);
        if(st.contains(fir)){return -1;}
        while(!q.empty()){
            int m = q.size();
            int store = q.front().second;
            for(int i =0;i<m;i++){
                auto it = q.front();
                q.pop();
                string pr = it.first;

                string orig = it.first;
                for(int j =0;j<4;j++){
                    int temp = pr[j]-'0';
                    int up = (temp+1+10)%10;
                    int down = (temp-1+10)%10;
                    pr[j]=up+'0';
                    if(target==pr){
                        return store+1;
                    }
                    if(!st.contains(pr)&&!vis.contains(pr)){
                        q.push({pr,store+1});
                        vis.insert(pr);
                    }
                    pr[j]=down+'0';
                    if(target==pr){
                        return store+1;
                    }
                    if(!st.contains(pr)&&!vis.contains(pr)){
                        q.push({pr,store+1});
                        vis.insert(pr);
                    }
                     pr = orig;
                }
               
            }
        }
        return -1;
    }
};