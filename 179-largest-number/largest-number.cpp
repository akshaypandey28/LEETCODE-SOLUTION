class Solution {
public:
    static bool cmp(string a,string b){
        //cout<<a<<" "<<b<<endl;
        if(a+b > b+a)return true; 
        return false;
    }
    string largestNumber(vector<int>& nums) {
        //sort it on the basis of lexographically order convert int into string
        vector<string> a;
        for(int i=0; i<nums.size(); i++) a.push_back(to_string(nums[i]));
        sort(a.begin(),a.end(),cmp);
        string ans="";
        for(int i=0; i<a.size(); i++) ans+=a[i];
        int zero=0;
        for(int i=0; i<ans.size(); i++) if(ans[i]=='0') zero++;
        if(zero==ans.size()) return "0";
        return ans;
    }
};