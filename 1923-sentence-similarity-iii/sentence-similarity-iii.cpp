class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) swap(s1, s2);

        vector<string> vec1, vec2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token) vec1.push_back(token);

        stringstream ss2(s2);
        while(ss2 >> token) vec2.push_back(token);

        int i = 0, j = vec1.size()-1; //s1 (vec1)
        int l = 0, r = vec2.size()-1; //s2 (vec2)

        while(l < vec2.size() && i < vec1.size() && vec2[l] == vec1[i]) {
            l++;
            i++;
        }

        while(r >= l && vec2[r] == vec1[j]) {
            j--;
            r--;
        }
        
        return r < l;

    }
};