#define pp pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;

        priority_queue<pp,vector<pp> ,greater<pp>> pq;
        vector<int> ans;
        for(auto ele:m)  {
            pq.push({ele.second,ele.first});
            if(pq.size()>k) pq.pop();
        }

        
        while(pq.empty()!=1){
            pp top=pq.top();
            ans.push_back(top.second);
            pq.pop();
        }
        return ans;
    }
};