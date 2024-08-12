class Solution {
public:
    int find(vector<int> &parent,int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent,parent[x]);
    }
    void Union(vector<int> &parent,int a,int b){
        a=find(parent,a);
        b=find(parent,b);
        if(a!=b) parent[b]=a;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(),parent.end(),0); 
        for(int i=0; i<edges.size(); i++) Union(parent,edges[i][0],edges[i][1]);

        for (int i = 0; i < n; i++) parent[i]=find(parent, i); // Compress the path and update parent array

        unordered_map<int,int> m;
        long long sum=n; //gives total number of nodes as prefix sum is required
        for(int i=0; i<n; i++) m[parent[i]]++;
        long long ans=0;
        for(auto ele:m){
            sum-=ele.second;
            ans+=sum*ele.second;
        }
        return ans;
    }
};