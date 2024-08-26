class Solution {
public:
    struct Edge{
        int src;
        int des;
        int wt;
    };
    
    vector<int> parent;

    // Find function for Union-Find
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    // Union function for Union-Find
    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;  // Union by rank can also be used here for optimization
        }
    }

    // Comparator function for sorting edges by weight
    static bool cmp(Edge e1, Edge e2) {
        return e1.wt < e2.wt;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);  // Resizing parent to have n elements
        
        // Initialize parent array
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        vector<Edge> edges;
        
        // Create all possible edges with their corresponding Manhattan distances
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, dist});
            }
        }
        
        // Sort edges using the custom comparator
        sort(edges.begin(), edges.end(), cmp);
        
        int mstCost = 0;
        int edgesUsed = 0;
        
        // Kruskal's Algorithm
        for (Edge &edge : edges) {
            if (find(edge.src) != find(edge.des)) {  // If they belong to different components
                Union(edge.src, edge.des);  // Union the components
                mstCost += edge.wt;
                edgesUsed++;
                if (edgesUsed == n - 1) break;  // MST is complete
            }
        }
        
        return mstCost;
    }
};
