class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        int dist[n][m];
        
        for(int i =0; i < n; i++)
            for(int j = 0; j < m; j++) 
                dist[i][j] = 1e9;
        
        deque<pair<int, int> > dq; //it stores the x and y coordinate
        dq.push_back({0, 0});
        dist[0][0] = 0; //this tells about the distance from source to any cell , for this source to source is 0
        
        while(not dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();
            int x = curr.first;
            int y = curr.second;
            int dir = grid[x][y];
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i]; //next x and y coordinate
                int ny = y + dy[i];
                //first right , then left , then down , then up
//suppose dir=1 it means right movement , so for (i+1==dir) checking and edge weight is 1 till now
//i==0 (0+1==1) means right is possible with edge weight 0 that's why edge weight gets updated to 0
//i==1 (1+1!=1) means right is not possible with edge weight 0 that's why edge weight doesn't gets updated to 0 that's still 1
//i==2 (2+1!=1) means right is not possible with edge weight 0 that's why edge weight doesn't gets updated to 0 that's still 1
//i==3 (3+1!=1) means right is not possible with edge weight 0 that's why edge weight doesn't gets updated to 0 that's still 1
                int edgewt = 1;
                if(i + 1 == dir) edgewt = 0;
                
                if(nx < n and ny < m and nx >= 0 and ny >= 0) {
                    // next cell lies in the grid
                    if(dist[nx][ny] > dist[x][y] + edgewt) {
                        dist[nx][ny] = dist[x][y] + edgewt;
                        if(edgewt == 1) {
                            dq.push_back({nx, ny}); //means movement in actually is not possible that's why this has to be processed at last
                        } else {
                            dq.push_front({nx, ny}); //means movement in actually is possible that's why this has to be processed first
                        }
                    }
                }
                
            }
            
            
        }
        return dist[n-1][m-1];
        
     }
};