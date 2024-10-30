class Solution {
public:
    int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> count(26,0);
        for(int i=0; i< s.size(); i++) count[s[i]-'a']++;

        while(t--){
            int z=count[25]; //store frequency of z because it contribute for a and b
            //means if number of z is 5 in ith loop then 5a and 5b is there for i+1 loop

            //in every iteration every character contributes for next character and increases its 
            //frequency by 1

            for(int i=24; i>=0; i--){
                count[i+1]=count[i];
                count[i]=0; //it is set for zero because for y=2 it changes in z for z=2 but 
                //y exists only if x exists in the string which gets change into y that's why it is
                //set for zero
            }

            count[0]+=z%mod;
            count[1]+=z%mod;
        }
        long long result=0;
        for(int i=0; i<26; i++){
            result+=count[i];
            result%=mod;
        }
        return result;
    }
};