class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() == 1)  return true;
        unordered_map<char, int> map;
        for (int i = 0; i < order.size(); i++) map[order[i]] = i;

        for (int i = 0; i < words.size() - 1; i++) {
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            bool diff=false;
            for(int j=0; j<len; j++){
                if(s1[j]!=s2[j]){
                    int order1=map[s1[j]];
                    int order2=map[s2[j]];
                    if(order1 > order2) return false;
                    diff=true;
                    break;
                }
            }
            if(diff==false and s1.size() > s2.size()) return false;
        }
        return true;
    }
};