class Solution {
public:
    int sum(int x,int y) {
        return x+y;
    }
    int climbStairs(int n) {
        //top down me 2 se 1 and 0 gya initially 1 and zero pe 1 value tha next value is sum of prev two 
        vector<int> store(n+1,1);
        for(int i=2;i<=n;i++){
            store[i]=sum(store[i-1],store[i-2]);
        }
        return store[n];
    }
};