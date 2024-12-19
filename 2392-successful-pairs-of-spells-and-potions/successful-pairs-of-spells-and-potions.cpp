class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        int n=spells.size();
        int m=potions.size();
        int maxPotion = potions[m-1];
        for(int i=0; i<n; i++){
            int spell = spells[i];
            
            long long minPotion = ceil((1.0*success)/spell);

            if(minPotion > maxPotion) {
                ans.push_back(0); //no pairs can be formed with the ith index
                continue;
            }

            int index = lower_bound(begin(potions), end(potions), minPotion) - begin(potions);
            
            ans.push_back(m-index); //denotes the no. of pairs can be made with ith index
        }
        return ans;
    }
};