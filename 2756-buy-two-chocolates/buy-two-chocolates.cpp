class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int buy=prices[0]+prices[1];

        return buy<=money ? money-buy : money;
    }
};