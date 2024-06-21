class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> m;
        int n=digits.size();
        for(int i=0; i<n; i++) m[digits[i]]++;
        vector<int> ans;
        for(int i=100; i<999; i+=2){
            unordered_map<int, int> q=m;
            int j=i;
            bool check=true;
            while(j>0){
                if(q[j%10]==0){
                    check=false;
                    break;
                }
                q[j%10]--;
                j=j/10;
            }
            if(check==true) ans.push_back(i);
        }
        return ans;
    }
};