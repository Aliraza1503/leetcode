class Solution {
public:
    int maximumSum(vector<int>& arr) {
      int n = arr.size();
      if(n==1)return arr[0];

      int maxi = *max_element(arr.begin(),arr.end());
      if(maxi<=0)return maxi;
      vector<int> pref(n);
      vector<int> suff(n);
      int val =0;
      for(int i=0;i<n;i++){
         val+=arr[i];
         
         if(val<0){
            val=0;
         }
         pref[i]=val;
         
      }  
      val =0;
        for(int i=n-1;i>=0;i--){
         val+=arr[i];
         
         if(val<0){
            val=0;
         }
         suff[i]=val;
         
      }  
      int ans =INT_MIN;
      ans = max(ans,suff[0]);
      for(int i=0;i<n;i++){
        if(i==0){
            int temp = suff[i+1];
            ans = max(ans,temp);
        }
        else if(i==n-1){
                int temp = pref[i-1];
              ans = max(ans,temp);
        }
        else {
            int temp = pref[i-1]+suff[i+1];
            ans = max(temp,ans);
        }
      }
      return ans;
    }
};