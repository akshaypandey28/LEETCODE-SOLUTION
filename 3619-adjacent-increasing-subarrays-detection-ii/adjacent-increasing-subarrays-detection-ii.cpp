class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        //Find the boundaries between strictly increasing subarrays and store it in the store
        //with the count
        vector<int> store;
        int count=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]<nums[i+1]) count++;
            else{
                store.push_back(count+1);
                count=0;
            }
        }
        store.push_back(count+1);
        
        //nums=[2,5,7,8,9,2,3,4,3,1]
        //store=[5,3,1,1]

        int ans=store[0]/2; //i can divide the store[0] into subarray strictly increasing 
        //subarray that's why divide by 2

        for(int i=1; i<store.size(); i++){
            //reduce the three if statements into a single line by finding max and min between 
            //consecutive value

            int maxi=max(store[i],store[i-1]);
            int mini=min(store[i],store[i-1]);
            ans=max({ans,mini,maxi/2});

            /* 
            if(store[i-1]>store[i]) ans=max({ans,store[i],store[i-1]/2}); //here value of 
            //minimum is taken into consideration and half of maximum

            else if(store[i-1]==store[i]) ans=max(ans,store[i]); ///two consecutive becomes 
            //equal then ans is max of ans,store[i]

            else ans=max({ans,store[i-1],store[i]/2}); //here value of 
            //minimum is taken into consideration and half of maximum 
            
            */
        }
        return ans;
    }
};