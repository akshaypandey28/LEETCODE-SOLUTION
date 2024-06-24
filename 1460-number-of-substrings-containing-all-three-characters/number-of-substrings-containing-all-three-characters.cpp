class Solution {
public:
    int numberOfSubstrings(string s) {
        
        //with every character there is a substring ends
        //the logic har index pr jana hai aur check krna hai ,kya us index se phle baki 2 characters aa chuke hai
        //agr aa chuke hai to v vector se minimum index find krna hai ,mtlb min index se phle se jitne charcters 
        //honge sare substring bna skte hai because sare characters aa chuke honge to unke sath min index se phle 
        //wale characters ko add krke substring bnaya ja skta hai

        //jaise bbacba //bac phla window hai jisme sare hai to including this and remaining b add ho jayenge to 2 ayega
        //same traverse krte rhna hai last tk 

        //b hi min index hai to min index=1
        //1+1=2
        vector<int> v(3,-1);
        int ans=0;
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']=i;
            if(v[0]!=-1 and v[1]!=-1 and v[2]!=-1){
                int mini=min({v[0],v[1],v[2]});
                ans+=mini+1;
            }
        }
        return ans;
    }
};