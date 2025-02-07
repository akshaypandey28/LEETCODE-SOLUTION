class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(char ch:s){
            if(st.empty()!=1 and ch=='*') st.pop();
            else st.push(ch);
        }
        string ans;
        while(st.empty()!=1){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};