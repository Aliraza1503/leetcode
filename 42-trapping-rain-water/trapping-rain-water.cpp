class Solution {
public:
    int trap(vector<int>& height) {
      //this is two pointer approach 
        // long long water = 0;
        // int left =0;
        // int right = height.size()-1;
        // int leftmax = 0,rightmax=0;
        // while(left<right){
        //     if(height[left]<height[right]){
        //         leftmax = max(leftmax,height[left]);
        //         water+=leftmax-height[left];
        //         left++;
        //     }
        //     else {
        //         rightmax = max(rightmax,height[right]);
        //         water+=rightmax-height[right];
        //         right--;
        //     }
        // }
        // return water;
        // this is approach by creating two arrays
    //     int n = height.size();
    //     vector<int> leftmax(n,0);
    //     vector<int> rightmax(n,0);
    //     leftmax[0] = height[0];
    //            for(int i =1;i<n;i++){
    //     leftmax[i]=max(leftmax[i-1],height[i]);
    //    }
    //    rightmax[n-1]= height[n-1];
    //      for(int i =n-2;i>=0;i--){
    //     rightmax[i]=max(rightmax[i+1],height[i]);
    //    }
    //    int long water = 0;
    // for(int i =0;i<n;i++){
    //    water+=max(0,min(leftmax[i],rightmax[i]))-height[i];
    // }
    // return water;
    stack<int> st;
    long long water = 0;
    for(int i =0;i<height.size();i++){
        while(!st.empty()&&height[i]>height[st.top()]){
            int mid = st.top();
            st.pop();
            if(!st.empty()){
            int left = st.top();
            water+= (i-left-1)*(min(height[i],height[left])-height[mid]);
            }
        }
        st.push(i);
    }

    return water;
}
};