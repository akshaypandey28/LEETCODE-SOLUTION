class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        unordered_map<char,int> m1,m2;
        for(int i=0; i<word1.size(); i++) m1[word1[i]]++;
        for(int i=0; i<word2.size(); i++) m2[word2[i]]++;
        //1st point - jo char word1 me hai, wo char word2 me bhi hona chaie
        for (char c : word1) if (!m2.count(c)) return false;
        
        for (char c : word2) if (!m1.count(c)) return false;
        
        vector<int> v1,v2;
        for(auto ele:m1) v1.push_back(ele.second);
        for(auto ele:m2) v2.push_back(ele.second);

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        return v1==v2;

    }
};