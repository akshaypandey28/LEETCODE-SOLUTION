class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> m;
        int freq=0;
        int domi;
        for(int ele:nums) {
            m[ele]++;
            if(m[ele] > freq){
                domi=ele;
                freq=m[ele];
            }
        }
        int n=nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==domi){
                count++; //denotes frequency of dominant in the left subarray 
                int right_freq=m[domi]-count;//denotes frequency of dominant in the right
                // subarray 

                int left=(i+1)/2;
                int right=(n-i-1)/2;
                if(count>left and right_freq>right) return i;
            }
        }
        return -1;
    }
};