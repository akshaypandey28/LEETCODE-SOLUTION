class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_set<int> st;
        int len=0;
        int l=0; //left 
        for(int i=0; i<s.size(); i++){ //i is right pointer
            if(st.find(s[i])!=st.end()){
                while(l<i and st.find(s[i])!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[i]);
            len=max(len,i-l+1);
        }
        return len;
    }
};
