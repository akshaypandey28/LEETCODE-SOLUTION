class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> m;
        for(int i=0; i<logs.size(); i++){
            m[logs[i][0]]++;
            m[logs[i][1]]--;
        }
        int year=0;
        int population=0;
        int temp=0;
        for(auto ele:m){
            temp+=ele.second;
            if(temp>population){
                population=temp;
                year=ele.first;
            }
        }
        return year;
    }
};