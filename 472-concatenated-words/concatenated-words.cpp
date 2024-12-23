//Using DFS and Memoization - O(N*L^3)
class Solution {
public:
    //if prefix and suffix both are in set then add it into result or prefix is in set and suffix is 
    //itself a concatenated word then add it into result that is word gets added in the result
    int n;
    unordered_map<string, bool> mp;
    //O(n*l*l*l*l) but because of Memoization it gets reduced to O(n*l^3)
    bool isConcat(string word, unordered_set<string>& st) {
        
        if(mp.find(word) != mp.end())  return mp[word];
        
        int l = word.length();
        
        for(int i = 0; i<l; i++) { //O(l)  2
            string prefix  = word.substr(0, i+1); //O(l)  3
            string suffix  = word.substr(i+1);
            
            //isConcat again contribute for O(2*3)=>O(l*l)
            if((st.find(prefix) != st.end() && isConcat(suffix, st)) || 
               (st.find(prefix) != st.end() && st.find(suffix) != st.end()))
                return mp[word] = true;
        }
        
        
        return mp[word] = false;
        
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        n = words.size();
        mp.clear();
        vector<string> result;
        unordered_set<string> st(begin(words), end(words));
        
        for(int i = 0; i<n; i++) { //O(n) 1
            if(isConcat(words[i], st))   result.push_back(words[i]);
        }
        
        return result;
    }
};