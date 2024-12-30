class Solution {
public:
    int maximum69Number (int num) {
        string value=to_string(num);
        int idx=value.find('6');
        if(idx==-1) return stoi(value);
        if(idx!=-1) value[idx]='9';
        return stoi(value);

    }
};