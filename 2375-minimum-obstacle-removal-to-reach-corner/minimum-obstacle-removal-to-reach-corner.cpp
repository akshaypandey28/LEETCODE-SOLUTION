//Approach (Using Dijkstra's Algorothm - Assuming obstacle with edge weight 1 and empty with 0)
//T.C : O(m*n log(m*n))
//S.C : O(m*n)
#define pp pair<int,pair<int,int>>
class Solution {
public:
    vector<int> directions = {-1,0,1,0,-1};
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        //result[i][j] = minimum distance/obstacleCount between [0][0] to [i][j]
        result[0][0] = 0;

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {0, 0}}); //{wt, {i, j}}
        //O(Elog(V))
        // E = number of edges = m*n
        // V = number of vertices = m*n
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for(int k=0; k<4; k++) {
                int x = i + directions[k];
                int y = j + directions[k+1];

                if(x < 0 || x >= m || y < 0 || y >= n) continue;

                int wt = (grid[x][y] == 1) ? 1 : 0;

                if(d + wt < result[x][y]) {
                    result[x][y] = d + wt;
                    pq.push({d+wt, {x, y}});
                }
            }
        }

        return result[m-1][n-1];
    }
};