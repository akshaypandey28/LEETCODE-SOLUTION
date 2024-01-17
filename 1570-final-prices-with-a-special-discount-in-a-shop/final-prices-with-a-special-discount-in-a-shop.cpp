class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        //next smaller element
        stack<int> s; //for storing the indexes
        s.push(0);
        for(int i=1; i<prices.size(); i++){
            while(s.empty()!=1 and prices[i] <= prices[s.top()]){
                prices[s.top()]=prices[s.top()]-prices[i];
                s.pop();
            }
            s.push(i);
        }
        return prices;
    }
};