class Solution {
public:
    vector<string> ans;
    vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void gen(string d,int i,string s){
        if(i==d.size()){
            ans.push_back(s);
            return ;
        }
        int digit=d[i]-'0';
        for(int j=0; j<v[digit].size(); j++){
            gen(d,i+1,s+v[digit][j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return ans;
        string s="";
        gen(digits,0,s);
        return ans;
    }
};