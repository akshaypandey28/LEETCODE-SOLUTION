class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(int i=0; i<s.size(); i++) {  //this loop is first transform so -1 from k
            int val=s[i]-'a'+1;
            while(val>0){
                sum=sum+val%10;
                val/=10;
            }
        } 
        k--;
        int ans=0;
        while(k>0){
            ans=0;
            while(sum>0){
                ans=ans + sum%10;
                sum/=10;
            }
            k--;
            sum=ans;
        }
        return sum;
        
    }
};