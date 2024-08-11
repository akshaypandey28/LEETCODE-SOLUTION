#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int> &parent, int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent, parent[x]);
    }

    void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
        a = find(parent, a);
        b = find(parent, b);
        if (a == b) return;
        if (rank[a] >= rank[b]) {
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        } else {
            parent[a] = b;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxR = 0, maxC = 0;
        for (auto ele : stones) {
            maxR = max(maxR, ele[0]);
            maxC = max(maxC, ele[1]);
        }
        int n = maxR + maxC + 2; // Ensure enough space for all rows and columns
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i; // Properly initialize parent array

        for (auto ele : stones) {
            int nodeR = ele[0];
            int nodeC = ele[1] + maxR + 1; // for nodeColumn=row+1+col and col is ele[1]
            Union(parent, rank, nodeR, nodeC);
        }

        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i && rank[i] > 0) {
                count++;
            }
        }

        return stones.size() - count;
    }
};
