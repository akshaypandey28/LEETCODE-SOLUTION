class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        st.push(0);
        vector<int> ans(temperatures.size());
        for(int i=1; i<temperatures.size(); i++){
            while(st.empty()!=1 and temperatures[i] > temperatures[st.top()]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        while(st.empty()!=1){
            ans[st.top()]=0;
            st.pop();
        }
        return ans;
    }
};