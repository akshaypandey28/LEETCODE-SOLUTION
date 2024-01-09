#define pp pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i=0; i<s.size(); i++){
            m[s[i]]++;
        }
        priority_queue<pp> pq;
        for(auto ele:m){
            pq.push({ele.second,ele.first});
        }
        s="";
        while(pq.empty()!=1){
            int value=pq.top().first;
            s.insert(s.size(),value,pq.top().second);
            pq.pop();
        }
        return s;
    }
};