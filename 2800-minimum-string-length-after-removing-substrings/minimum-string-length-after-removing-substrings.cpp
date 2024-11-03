class Solution {
public:
    int minLength(string s) {
        while(s.find("AB")!=-1 || s.find("CD")!=-1){
            int idx=s.find("AB");
            if(idx!=-1) s.erase(idx,2);
            idx=s.find("CD");
            if(idx!=-1) s.erase(idx,2);
        }
        return s.size();
    }
};