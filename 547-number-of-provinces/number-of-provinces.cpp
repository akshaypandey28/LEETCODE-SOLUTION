class Solution {
public:
    int find(vector<int> &parent,int x){
        // TX:(log*n);
        // This method returns which group/cluster x belongs to
        if(parent[x]==x) return x;
        return parent[x]=find(parent,parent[x]);
    }
    void Union(vector<int> &parent,int a, int b) {
    // TX:(log*n);
        a = find(parent, a);
        b = find(parent, b);
        if(a!=b) parent[b]=a;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> parent(n);
        iota(parent.begin(),parent.end(),0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){ 
                //1 means there is an edge between i and j
                if(isConnected[i][j]==1) Union(parent,i,j);
            }
        }
        int count=0;
        for(int i=0; i<n; i++){
            if(parent[i]==i) count++;
        }
        return count;
    }
};