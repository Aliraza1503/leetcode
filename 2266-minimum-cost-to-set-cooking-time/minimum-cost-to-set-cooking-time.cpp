class Solution {
public:
    int minCostSetTime(int start, int move, int push, int tar) {
          vector<string> ways;
        int mins = 0; 
        while(tar >= 100)
        {
            mins++;
            tar -= 60;
        }
        string s = "";
        while(tar >= 60)
        {
            s = "";
            if(mins != 0)
                s += to_string(mins);
            s += to_string(tar);
            ways.push_back(s);
            tar -= 60;
            mins++;
        }
        s = "";
        if(mins >= 100)
            goto section4;
        if(mins != 0)
            s += to_string(mins);
        if(tar >= 10)
            s += to_string(tar);
        else if(tar>0 and tar < 10)
        {
            if(mins != 0)
                s += "0" + to_string(tar);
            else s += to_string(tar);
        }
        else if(tar == 0)
            s += "00";
        ways.push_back(s);
        
		
		//Section 4
        section4:
        int ans = INT_MAX; 
        for(auto s : ways)
        {
            int len = s.size(); 
            int sub = 0; 
            char cur = to_string(start)[0];
            for(int i =0; i<len; i++)
            {
                if(cur != s[i])
                {
                    sub += move;
                    cur = s[i];
                }
                sub += push;
            }
            ans = min(ans, sub);
        }
        
        return ans; 
    }
};