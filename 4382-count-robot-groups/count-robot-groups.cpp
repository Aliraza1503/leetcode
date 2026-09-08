class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        /*
        positions 1 5 6 20 
        speed     4 3 2 3
        dist 1
        int ans =1;
        first priority distance if less than or equal then iterate pointer
        second priority speed if speed is greater than previous speed then it will catch up as well
        pointer from i = n-2;

        */
        int ans=1;
        int n = position.size();
        int prevpos = position[n-1];
        int prevspeed = speed[n-1];
        int i = n-2;
        while(i>=0){
            int curpos = position[i];
            int curspeed = speed[i];
            if(prevpos-curpos<=distance){
                i--;
                prevpos = curpos;
                
            }
            else if(curspeed>prevspeed){
                i--;
                prevpos = curpos;
                
            }
            else {
                ans++;
                i--;
                prevpos = curpos;
                prevspeed = curspeed;
            }
        }
        return ans;
    }
};