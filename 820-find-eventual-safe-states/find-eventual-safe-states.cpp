class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int v=adj.size();

        //reverse the edges as in the question ask for outdegree then it converts into indegree
        vector<vector<int>> graph(v);
        vector<int> indegree(v,0);
        for(int i=0; i<v; i++){
            for(auto neighbour:adj[i]){
                graph[neighbour].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> ans;
        queue<int> qu;
        for(int i=0; i<v; i++){
            if(indegree[i]==0) qu.push(i);
        }

        while(not qu.empty()) {
            int node = qu.front();
            ans.push_back(node);
            qu.pop();
            for(auto neighbour : graph[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)  qu.push(neighbour);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};