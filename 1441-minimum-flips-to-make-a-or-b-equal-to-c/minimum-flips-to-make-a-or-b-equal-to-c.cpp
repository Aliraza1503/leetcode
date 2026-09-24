class Solution {
public:
    int minFlips(int a, int b, int c) {
        /*
          a 10 
          b110
          c101
          // approach
          leftshit^1==0?leftshift = 1:0;
           check c 1 ab=0 and ab1 or else no check 
           check c =0 
           got the lotic right 
        */
        int ans =0;
        for(int i=0;i<31;i++){
                int cright = (c>>i)&1;
                int bright = (b>>i)&1;
                int aright = (a>>i)&1;
                if(cright==0){
                    if(aright==1&&bright==1){
                        ans+=2;
                    }
                    else if(aright==1||bright==1){
                        ans+=1;
                    }
                }
                else{
                    if((aright==0&&bright==0)){
                        ans+=1;
                    }
                }
        }
        return ans;
    }
};