class Solution {
public:
    vector<list<int>> graph;
    vector<int> ans;
    int v;
    void topoBFS() {
    // Kahn algo
    vector<int> indegree(v, 0);
    for(int i = 0 ; i < v; i++) {
        for(auto neighbour : graph[i]) {
            // i ---> neighbour (i to neighbour edge)
            indegree[neighbour]++;
        }
    }
    queue<int> qu; //stores value whose indegree is zero
    unordered_set<int> vis; //check vis for value whose indegree is zero
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            qu.push(i);
            vis.insert(i);
        }
    }
    
    while(not qu.empty()) {
        int node = qu.front();
        ans.push_back(node);
        qu.pop();
        for(auto neighbour : graph[node]) {
            if(not vis.count(neighbour)) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    qu.push(neighbour);
                    vis.insert(neighbour);
                }
            }
        }
    }
} 
    bool canFinish(int n, vector<vector<int>>& pre) {
        v=n;
        graph.resize(v, list<int> ());
        for(int i=0; i<pre.size(); i++) graph[pre[i][1]].push_back(pre[i][0]);
        topoBFS();
        if(ans.size()==n) return true;
        return false;

    }
};