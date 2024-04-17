class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        string a="";
        for(int i=0; i<n; i++) a.push_back(nums[i]+'0');
        string b=a+a;
        sort(a.begin(),a.end());
        return b.find(a)!=-1;
        
    }
};