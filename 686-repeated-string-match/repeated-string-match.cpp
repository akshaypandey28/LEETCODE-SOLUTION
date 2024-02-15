class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int foundinb=b.find(a);
        int ans=0;
        if(foundinb>=0){
            int found=a.find(b);
            string copy=a;
            while(found<0){
                a=a+copy;
                ans++;
                found=a.find(b);
                if(found < 0 and a.size() > b.size()) {
                    a=a+copy;
                    found=a.find(b);
                    if(found>=0){
                        ans++;
                    }
                    else return -1;
                }
            }
            return ans+1;
        }
        int foundina=a.find(b);
        if(foundina >= 0) return 1;
        a=a+a;
        foundina=a.find(b);
        if(foundina >= 0) return 2;
        else return -1;
    }
};