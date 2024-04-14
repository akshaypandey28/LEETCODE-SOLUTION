class KthLargest {
public:
    priority_queue<int,vector<int> , greater<int> > pq; 
    int size;
    //in this problem i am tyring to fix the size of pq equal to k such that kth largest is at the top
    //of pq 
    //how????
    //answer if pq.size()==k always that is what i am doing in my solution then kth largest let's k=4
    //then 4th largest element is (if pq.size()==k always) 1st smallest element accroding to our pq
    //1st largest element is let's suppose at the last of pq
    //2nd is at second position from last  
    //3rd is at third position from last
    //and 4th is at fourth position from last and 4 is the size of pq then top of the pq is my answer
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size() > size) pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */