class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        int minLen=INT_MAX;
        int count=0;
        for(int i=0; i<t.size(); i++) m[t[i]]++;
        int start_idx=-1;
        int l=0,r=0;

        while(r<s.size()){
            if(m[s[r]]>0) count+=1;
            m[s[r]]--;

            while(count==t.size()){
                if(r-l+1 < minLen){
                    minLen=r-l+1;
                    start_idx=l;
                }

                m[s[l]]++;
                if(m[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return start_idx==-1 ? "" : s.substr(start_idx,minLen);
    }
};