class Solution {
public:
    // if frequency of any value (freq==1) return -1
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(int i=0; i<tasks.size(); i++) m[tasks[i]]++;

        int ans=0;
        for(auto ele:m){
            if(ele.second==1) return -1;

            if(ele.second%3==0) ans+=ele.second/3; //3k

            else ans+=(ele.second/3)+1; //(3k+1) and (3k+2) frequency count
        }
        return ans;
    }

};