class Solution {
public:
    vector<int> rank, parent;
    int find(int x){
        // TX:(log*n);
        // This method returns which group/cluster x belongs to
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int a, int b) {
        // TX:(log*n);
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(rank[a] >= rank[b]) {
            rank[a]++;
            parent[b] = a;
        } else {
            rank[b]++;
            parent[a] = b;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        unordered_map<string,int> m;

        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail=accounts[i][j];
                if(m.find(mail) == m.end()) m[mail]=i;
                else Union(i,m[mail]);
            }
        }

        vector<vector<string>> ans(n);
        for(auto ele:m){
            int a=find(ele.second);
            string mail=ele.first;

            ans[a].push_back(mail);
        }

        vector<vector<string>> result;

        for(int i=0; i<n; i++){
            if(ans[i].size()==0) continue;

            vector<string> v;

            v.push_back(accounts[i][0]); //name

            for(string mail:ans[i]) v.push_back(mail);

            sort(v.begin()+1,v.end());

            result.push_back(v);
        }
        return result;
    }
};