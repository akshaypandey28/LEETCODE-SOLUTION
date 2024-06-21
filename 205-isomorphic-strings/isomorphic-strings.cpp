class Solution {
public:
    bool isIsomorphic(string str1, string str2) {
        if(str1.size()!=str2.size()) return false;
        unordered_map<char,char> m1,m2;
        for(int i=0; i<str1.size(); i++){
            if(m1.count(str1[i]) && m1[str1[i]]!=str2[i]) return false;
            else m1[str1[i]]=str2[i];
            
            if(m2.count(str2[i]) && m2[str2[i]]!=str1[i]) return false;
            else m2[str2[i]]=str1[i];
        }
        return true;
    }
};