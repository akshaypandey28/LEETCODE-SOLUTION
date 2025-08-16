#define pp pair<int,int>
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=customers[0][1];
        int n=customers.size();
        int prev_finished=customers[0][0] + customers[0][1];
        for(int i=1; i<n; i++){
            int customer_arrive=customers[i][0];

            //at what chef will start cooking 
            int start_cooking=max(customer_arrive,prev_finished);
            
            int end_cooking=start_cooking+customers[i][1];
            ans+=end_cooking-customer_arrive;
            prev_finished=end_cooking;
        }
        return ans/n;
    }
};