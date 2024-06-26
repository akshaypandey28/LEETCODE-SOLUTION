class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum=0; //it represents prefix sum
        int ans=0;
        m[0]=1; //corner case
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()) ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};