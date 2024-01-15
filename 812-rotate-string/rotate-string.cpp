class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        goal=goal+goal;
        if(goal.find(s)!=-1) return true;
        return false;
    }
};