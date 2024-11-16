class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result(n-k+1, -1);

        int count = 1; //count of consecutive elements

        //preprocess the first window 
        //point => if answer is computed it means no. of consecutive elements is equal to k
        for(int i = 1; i < k; i++) {
            if(nums[i] == nums[i-1]+1) count++;

            else count = 1;
        }

        if(count == k) result[0] = nums[k-1];

        int i = 1;
        int j = k;

        while(j < n) {
            if(nums[j] == nums[j-1]+1) count++;

            else count = 1;
            
            if(count >= k)  result[i] = nums[j];
            
            i++;
            j++;
        }
        return result;
    }
};