class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stack<char> st;
        bool flag=false;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                while(st.empty()!=1){
                    ans.push_back(st.top());
                    st.pop();
                    flag=true;
                }
                if(flag==true) {
                    ans.push_back(' ');
                    flag=false;
                }
            }
            else{
                st.push(s[i]);
                //flag=false;
            }
        }
        while(st.empty()!=1){
            ans.push_back(st.top());
            st.pop();
        }
        if(ans[ans.size()-1]==' ') ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};