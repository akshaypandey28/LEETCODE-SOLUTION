class Solution {
public:
    //k is source node
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n+1, INT_MAX); 
        vector<list<pair<int,int>> > graph(n+1);
        
        
        for(int i=0; i<times.size(); i++){
            int x=times[i][0];
            int y=times[i][1];
            int wt=times[i][2];
            graph[x].push_back({y,wt});
        }

        queue<pair<int, int>> que; //node , distance
        que.push({k, 0});
        distance[k] = 0;

        while(!que.empty()) {
            int N = que.size();
            
            while(N--) {
                int u = que.front().first; //curr node
                int d = que.front().second; //curr distance
                que.pop();
                
                for(auto &P: graph[u]) {
                    
                    int v    = P.first;
                    int cost = P.second;
                    
                    if(distance[v] > d + cost) {
                        distance[v] = d + cost;
                        que.push({v, d+cost});
                    }
                }
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++){
            if(distance[i]==INT_MAX) return -1;
            ans=max(ans,distance[i]);
        }
        return ans;
    }
};