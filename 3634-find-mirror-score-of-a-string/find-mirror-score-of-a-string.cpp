class Solution {
public:
    long long calculateScore(string s) {
        int n=s.size();
        vector<bool> visited(n,false);
        long long ans=0;
        unordered_map<int,vector<int> > m;
        for(int i=0; i<n; i++){
            int ch=s[i]-'a';
            int mirror=25-ch;

            if(m.find(mirror)!=m.end()){
                int j=m[mirror].back();
                ans+=(long long)i- (long long)j;

                m[mirror].pop_back();
                if(m[mirror].size()==0) m.erase(mirror);
            }
            else m[ch].push_back(i);
        }
        return ans;
    }
};