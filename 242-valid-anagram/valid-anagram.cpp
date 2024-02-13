class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char,int> m,n;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
            n[t[i]]++;
        }
        for(auto ele:m){
            if(n.find(ele.first)==n.end()) return false;
            else{
                if(ele.second!=n[ele.first]) return false;
            }
        }
        return true;
        
    }
};