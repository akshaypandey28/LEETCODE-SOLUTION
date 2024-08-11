class Solution {
public:
    // DSU to find the number of connected component
    // ans = number of nodes - number of connected component
    // as in every connected component every node gets destroyed except one node which is not part of the answer
    // so basically after these steps every connected component has 1 node if 5 connected component then every has 1, total 5 nodes remain undestroyed

    int find(vector<int> &parent, int x) {
        // TX:(log*n);
        // This method returns which group/cluster x belongs to
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }

    void Union(vector<int> &parent, int a, int b) {
        // TX:(log*n);
        a = find(parent, a);
        b = find(parent, b);
        if (a != b) {
            parent[b] = a;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxR = 0, maxC = 0;
        for (auto ele : stones) {
            maxR = max(maxR, ele[0]);
            maxC = max(maxC, ele[1]);
        }
        int n = maxR + maxC + 2; // Ensure enough space for all rows and columns
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        for (auto ele : stones) {
            int nodeR = ele[0];
            int nodeC = ele[1] + maxR + 1; // for nodeColumn=row+1+col and col is ele[1]
            Union(parent, nodeR, nodeC);
        }

        unordered_set<int> uniqueRoots;
        for (auto ele : stones) {
            uniqueRoots.insert(find(parent, ele[0]));
            uniqueRoots.insert(find(parent, ele[1] + maxR + 1));
        }

        return stones.size() - uniqueRoots.size();
    }
};
