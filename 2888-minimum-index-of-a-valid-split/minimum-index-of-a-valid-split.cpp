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
        int left_freq=0;
        for(int i=0; i<n; i++){
            if(nums[i]==domi){
                left_freq++; //denotes frequency of dominant in the left subarray 
                int right_freq=m[domi]-left_freq;//denotes frequency of dominant in the
                // right subarray 

                int left_size=i+1;
                int right_size=n-i-1;
                if(left_freq>left_size/2 and right_freq>right_size/2) return i;
            }
        }
        return -1;
    }
};