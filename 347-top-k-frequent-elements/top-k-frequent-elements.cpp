#define pp pair<int, int>
class Solution {
public:
    // static bool check(const pp& p1, const pp& p2){
        
    //     if (p1.first == p2.first) {
    //         return p1.second  < p2.second ;
    //     }
    //     // compare based on the integer value
    //     return p1.first > p2.first;
    //}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++) m[nums[i]]++;

        priority_queue<pp> pq;

        for(auto ele:m)  pq.push({ele.second,ele.first});

        vector<int> ans;
        while(k--){
            pp top=pq.top();
            ans.push_back(top.second);
            pq.pop();
        }
        return ans;
        
    }
};