class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st;
        for(int i =0;i<bank.size();i++){
            st.insert(bank[i]);
        }
        queue<pair<string,int>> q;
        string check = "ACGT";
        q.push({startGene,0});
        if(startGene==endGene) return 0;
        while(!q.empty()){
            auto [str,freq]=q.front();
                q.pop();
                string temp = str;
                for(int i =0;i<8;i++){
                    for(int j =0;j<4;j++){
                        if(check[j]!=str[i]){
                            str[i]=check[j];
                            if(st.contains(str)){
                                st.erase(str);
                                 q.push({str,freq+1});
                                   if(str==endGene){
                                return freq+1;
                            }
                            }
                           
                          
                            str = temp;
                        }
                    }
                }
        }
        return -1;
    }
};