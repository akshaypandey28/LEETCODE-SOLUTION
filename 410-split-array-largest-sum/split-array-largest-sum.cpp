class Solution {
public:
//same as book allocation problem
    int f(vector<int> a,int mid,int n){
        int count=1;
        long long sum=0;
        for(int i=0; i<n; i++){
            if(sum+a[i]<=mid){
                sum+=a[i];
            }
            else{
                count++;
                sum=a[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);

        while(l<=h){
            int mid=(l+h)/2;
            
            int partitions=f(nums,mid,nums.size());

            if(partitions > k) l=mid+1;
            else h=mid-1;
        }
        return l;
    }
};