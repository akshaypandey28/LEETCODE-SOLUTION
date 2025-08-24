class Solution {
public:
    vector<int> parent;
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
        parent[b] = a;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        parent.resize(n);
        int extraWires=0;
        for (int i = 0; i < n; i++) parent[i] = i;

        for(auto ele:connections) Union(ele[0],ele[1]);

        int connectedComponent=0;
        for(int i=0; i<n; i++){
            if(find(i)==i) connectedComponent++;
        }

        int wiresToBeNeeded=connectedComponent-1;

        return wiresToBeNeeded;
    }
};



/* DFS
class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src){
        visited[src] = true;
        for(int i : adj[src])
            if(!visited[i])
                dfs(adj, visited, i);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<vector<int>> adj(n);
        for(auto c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i]){
                dfs(adj, visited, i);
                components++;
            }
        return components - 1;
    }
};
 */