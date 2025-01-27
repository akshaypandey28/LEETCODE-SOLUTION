//self
//T.C => O( (m+n)logn )
//S.C=> O(n+m)
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> s; //occupied position 
        int n=nums.size(),m=moveFrom.size();
        for(int i=0; i<n; i++) s.insert(nums[i]); //O(n)

        //O(m*logn)
        for(int i=0; i<m; i++){ //O(m)
            s.erase(moveFrom[i]); //erase all marbles on this position and move it to 
            //moveTo][i] position
            s.insert(moveTo[i]);

            //erase and insert O(logn)
        }
        vector<int> ans;
        for(auto ele:s) ans.push_back(ele);
        sort(ans.begin(),ans.end()); //O(nlogn)
        return ans;

    }
};