class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int> ,greater<int> > pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};


/* 
//Approach-3 (Using QuickSelect Algorithm
//Time complexity: O(n) on average, O(n2) in the worst case (See video above for explanation)
class Solution {
public:
    
    int partition_algo(vector<int>& nums, int L, int R) {
        
        int P = nums[L];
        int i = L+1; //0
        int j = R; //0
        
        while(i <= j) {
            
            if(nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            
            if(nums[i] >= P) i++;
            
            if(nums[j] <= P) j--;
            
        }
        
        swap(nums[L], nums[j]);
        return j; //P is at jth index
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        int L = 0;
        int R = n-1;
        
        int pivot_idx = 0;
        
        //kth largest pivot element - nums[k-1] (descending order me partition karenge)
        
        while(true) {
            
            pivot_idx = partition_algo(nums, L, R);
            
            if(pivot_idx == k-1) break;
            
            else if(pivot_idx > k-1) R = pivot_idx - 1;  //2nd largest , 4th largest

            else  L = pivot_idx + 1;
            
        }
        
        
        return nums[pivot_idx];
        
    }
}; */