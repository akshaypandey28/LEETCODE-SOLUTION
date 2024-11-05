class Solution {
public:
    int minChanges(string s) {
        //make only 1's
        int count=0; //zero
        for(int i=0; i<s.size(); i+=2){
            if(s[i]!=s[i+1]) count++;
        }
        return count;
    }
};