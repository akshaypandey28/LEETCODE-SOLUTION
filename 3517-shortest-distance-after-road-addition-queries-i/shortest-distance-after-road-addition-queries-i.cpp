class Solution {
public:

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<list<int>> graph(n);

        for (int i = 0; i < n - 1; i++) graph[i].push_back(i + 1);
        for (const auto& i : queries) {
            int u = i[0];
            int v = i[1];
            graph[u].push_back(v);

            vector<int> dist(n, INT_MAX);
            dist[0] = 0;
            queue<int> q;
            q.push(0);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int it : graph[node]) {
                    if (dist[node] + 1 < dist[it]) {
                        dist[it] = dist[node] + 1;
                        q.push(it);
                    }
                }
            }
            int shortest = dist[n - 1];
            if (shortest== INT_MAX) ans.push_back(-1);
            else ans.push_back(shortest);
        }
        return ans;  
    }
};