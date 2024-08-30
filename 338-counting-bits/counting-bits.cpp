class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0; i<n+1; i++){
            int j=i;
            int count=0;
            while(j>0){
                if(j%2==1) count++;
                j/=2;
            }
            ans[i]=count;
        }
        return ans;
    }
};