/*Approach 
any node whose parent are same then they can reach to each other but if the parent of one node differs than other node
then they are unreachable
firstly i apply DSU to make parent vector 
groups gets formed because of DSU
count which which nodes parent are same and stored it in vector
there are n(7) nodes available 
if 4 nodes have parent 0
2 nodes have parent 1
and 1 nodes have parent itself (3)
means traverse the map 
first iteration tells that 4 nodes whose parent is 0 they are unreachable to other 3 nodes which helps in making pairs
subtract 7-ele.second(4) = 3 nodes are unreachable from 4 other nodes which make 12 pairs and n becomes(7-4) = 3
and so on after this same process continues
 */
class Solution {
public:
    int find(vector<int> &parent,int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent,parent[x]);
    }
    void Union(vector<int> &parent,int a,int b){
        a=find(parent,a);
        b=find(parent,b);
        if(a!=b) parent[b]=a;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(),parent.end(),0); 
        for(int i=0; i<edges.size(); i++) Union(parent,edges[i][0],edges[i][1]);

        for (int i = 0; i < n; i++) parent[i]=find(parent, i); // Compress the path and update parent array

        unordered_map<int,int> m;
        long long sum=n; //gives total number of nodes as prefix sum is required
        for(int i=0; i<n; i++) m[parent[i]]++;
        long long ans=0;
        for(auto ele:m){
            sum-=ele.second;
            ans+=sum*ele.second;
        }
        return ans;
    }
};