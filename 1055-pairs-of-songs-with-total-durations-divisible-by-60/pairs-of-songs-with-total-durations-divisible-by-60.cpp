class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> m;
        int count=0;
        for(int i=0; i<time.size(); i++){
            int a=time[i]%60;
            int req=(60-a)%60;
            if(m.find(req)!=m.end()) count+=m[req];
            m[a]++;
        }
        return count;
    }
};