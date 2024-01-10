class Solution {
public:

    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum=0.0;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]*1.0); //for making decimal
            sum+=nums[i];
        }
        double required_sum=sum/2.0;
        int count=0;
        while(sum > required_sum){
            double el=pq.top();
            pq.pop();
            sum-=el/2.0;
            pq.push(el/2.0);
            count++;
        }
        return count;
    }
};