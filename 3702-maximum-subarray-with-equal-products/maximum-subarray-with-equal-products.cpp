class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=2; //minimum of two maxLength
        for(int i=0; i<nums.size(); i++){
            long long g=nums[i],l=nums[i],p=nums[i];
            long long maxLcm=1e10; //maxLcm can be of 10 factorial or less than

            for(int j=i+1; j<nums.size(); j++){
                p=p*(long long)nums[j];

                if(p>maxLcm) break;
                g=gcd(g,(long long)nums[j]);
                l=lcm(l,(long long)nums[j]);

                if(p==g*l) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};