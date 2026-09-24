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
        //method 1
        // int ans =0;
        // for(int i=0;i<31;i++){
        //         int cright = (c>>i)&1;
        //         int bright = (b>>i)&1;
        //         int aright = (a>>i)&1;
        //         if(cright==0){
        //           ans+=bright+aright;
        //         }
        //         else{
        //             if((aright==0&&bright==0)){
        //                 ans+=1;
        //             }
        //         }
        // }
        // return ans;


        //method 2 convert bit to string best thing i study today 
         
         int ans =0;
         string fir = bitset<31>(a).to_string();
         string sec = bitset<31>(b).to_string();
         string thir = bitset<31>(c).to_string();


         for(int i=0;i<31;i++){
            if(thir[i]=='0'){
                ans+=((fir[i]-'0')+(sec[i]-'0'));
            }
            else{
                ans+= (fir[i]=='0'&&sec[i]=='0')?1:0;
            }
         }
        return ans;

    }
};