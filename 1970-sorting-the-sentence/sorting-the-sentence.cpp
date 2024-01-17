class Solution {
public:
    string sortSentence(string s) {
        int j=0;
        //vector<string> v(200);
        map<int,string> m;
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                string b=s.substr(j,i-j);
                int digit=s[i]-'0';
                m[digit]=b;
                j=i+2;
            }
        }
        s="";
        for(auto ele:m){
            s+=ele.second+" ";
        }
        s.pop_back();
        return s;
    }
};