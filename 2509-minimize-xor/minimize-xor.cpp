class Solution {
public:
    int minimizeXor(int num1, int num2) {
      int cnt =0;
      while(num2){
        num2&=(num2-1);
        cnt++;
      }
      //there is two condition here
      int val =0;
      for(int i=31;i>=0&&cnt>0;i--){
        if(num1&(1<<i)){
            val|=(1<<i);
               cnt--;
        }
      }
      //if num1count is less than num2 then we add 1s in rightside
          for (int i = 0; i <= 31 && cnt > 0; i++) {
            if (!(num1 & (1<<i))) {
                val |= (1 << i);
                cnt--;
            }
        }
        return val;

    }
};