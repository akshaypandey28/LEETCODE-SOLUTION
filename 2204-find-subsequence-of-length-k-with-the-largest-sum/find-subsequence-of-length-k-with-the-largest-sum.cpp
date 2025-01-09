#define pp pair<int,int>
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pp,vector<pp>,greater<pp> > pq;
        int i=0; 
        int n=nums.size();
        while(i<n){
            pq.push({nums[i],i});
            if(pq.size()>k) pq.pop();
            i++;
        }
        vector<int> ans;
        map<int,int> m;
        while(pq.empty()!=1){
            m[pq.top().second]=pq.top().first;
            pq.pop();
        }
        for(auto ele:m) ans.push_back(ele.second);
        return ans;
    }
};