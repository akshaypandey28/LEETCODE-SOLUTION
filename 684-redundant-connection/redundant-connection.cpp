//Approach-3 (DSU - Union Find with Path compression)
//T.C : O(n * alpha(n))
//S.C : O(n)
class Solution {
public:
        vector<int> parent;
        vector<int> rank;

       
        int find(int x) {
        if(x == parent[x]) return x;

        return parent[x] = find(parent[x]); //path compression
    }

    void Union(int x, int y) {
        x = find(x);
        y = find(y);

        if(x == y) return;
        
        if(rank[x] >= rank[y]) {
            rank[x]++;
            parent[y] = x;
        } 
        else {
            parent[x] = y;
            rank[y]++;
        } 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n+1); //1, 2, 3, 4, 5.., n
        rank.resize(n+1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        //T.C : DSU = alpha(n)

        //T.C : O(n * alpha(n))
        for(auto &edge : edges) { //O(n)
            int u = edge[0];
            int v = edge[1];

            if(find(u) == find(v)) return edge;
            
            Union(u, v);
        }

        return {};
    }
};

