class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        st.push(0); //storing indexes instead of element but it represents elements
        //stack elements are in decreasing order

        for(int i=1; i<n;i++){
            while(st.empty()!=1 and nums[i]>nums[st.top()]){
                ans[st.top()]=nums[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int> idx;
        for(int i=0; i<n; i++){
            if(st.empty()) break;
            while(st.empty()!=1 and nums[i] > nums[st.top()]){
                ans[st.top()]=nums[i];
                st.pop();
            }
        }
        // ans[st.top()]=-1;
        // for(int i=0; i<idx.size(); i++){
        //     if(nums[idx[i]]!=nums[st.top()]) ans[idx[i]]=nums[st.top()];
        // }
        return ans;
    }
};