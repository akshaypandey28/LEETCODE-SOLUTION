class Solution {
public:
    int intersects(vector<int>&a,vector<int>&b,int k){
        int cnt =0;
        unordered_set<int>st2;
        unordered_set<int>st(b.begin(),b.end());
        for(int i=0;i<a.size();i++){
             if(st2.count(a[i])>0){
                continue;
            }else if(st.count(a[i])>0){
                st2.insert(a[i]);
                cnt++;
                if(cnt>=k){
                    break;
                }
            }

        }
        return cnt;

    }
    void dfs( unordered_map<int,vector<int>>&adj,vector<bool>&visited,int node){
        visited[node]=true;
        for(auto &ngbr:adj[node]){
            if(!visited[ngbr]){
                dfs(adj,visited,ngbr);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        unordered_map<int,vector<int>>adj;
        int n = properties.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(intersects(properties[i],properties[j],k)>=k){
                    adj[i].push_back(j);
                    adj[j].push_back(i);

                }
            }
        }
        int ans = 0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                ans++;
            }
            
        }
        return ans;
        
    }
};