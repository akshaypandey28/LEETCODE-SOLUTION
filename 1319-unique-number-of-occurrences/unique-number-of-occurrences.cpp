class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        set<int> s;
        for(int i=0; i<arr.size(); i++){
            m[arr[i]]++;
        }
        for(auto ele:m){
            s.insert(ele.second);
        }
        return m.size()==s.size();
    }
};