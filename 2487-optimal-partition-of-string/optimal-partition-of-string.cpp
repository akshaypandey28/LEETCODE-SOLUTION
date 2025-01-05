class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);
        
        int count = 0;
        int substringStart = 0;

        for (int i = 0; i < s.length(); i++) {
            if (lastSeen[s[i] - 'a'] >= substringStart) {
                count++;
                substringStart = i;
            }
            lastSeen[s[i] - 'a'] = i;
        }

        return count+1; //+1 because 1 substring gets remaining
    }
};

/* 
self 
class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        string temp="";
        for(char ch:s){
            if(temp.find(ch)!=-1){
                temp="";
                ans++;
                temp.push_back(ch);
            }
            else temp.push_back(ch);
        }
        if(temp.size()!=0) ans++;
        return ans;
    }
};

self
class Solution {
public:
    int partitionString(string s) {
        int ans=0;
        unordered_set<char> seen; 
        for(char ch:s){
            if(seen.find(ch)!=seen.end()){
                ans++;
                seen.clear();
            }
            seen.insert(ch);
        }
        if(seen.size()!=0) ans++;
        return ans;
    }
};
 */