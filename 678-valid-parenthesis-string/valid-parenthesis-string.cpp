class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0;
//mini and maxi are range , mini is for ) and maxi is for (
//mini can never be negative it must be start from 0 at least
        for(char c:s){
            if(c=='('){
                mini++;
                maxi++;
            }
            else if(c==')'){
                mini--;
                maxi--;
            }
            else {
                mini--;
                maxi++;
            }
            if(mini<0) mini=0;//Because we can't have negative open brackets in reality
            if(maxi<0) return false;//We have seen too many closing brackets ), more than we could possibly balance
        }
        return mini==0;
    }
};