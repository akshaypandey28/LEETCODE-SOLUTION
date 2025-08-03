#define pp pair<int,string>
class TimeMap {
public:
    unordered_map<string,vector<pp>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &ele=m[key];
        int l=0,h=ele.size()-1;
        string ans="";
        while(l<=h){
            int mid=l+(h-l)/2;
            if(ele[mid].first<=timestamp){
                ans=ele[mid].second;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */