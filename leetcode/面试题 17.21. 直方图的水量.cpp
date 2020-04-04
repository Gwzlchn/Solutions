class Solution {
public:
    int trap(vector<int>& height) {
       stack<int> mono_st;
       int res= 0;
       for(int i=0;i<height.size();i++){
           while(!mono_st.empty() && height[mono_st.top()] < height[i]){
               int cur_max_idx = mono_st.top();
               mono_st.pop();
               if(mono_st.empty()) continue;
               int cur_length = i - mono_st.top() -1;
               int cur_height = min(height[i],height[mono_st.top()]) - height[cur_max_idx];
               res += cur_length*cur_height;
           }
           mono_st.push(i);
       }

       return res;
    }
};