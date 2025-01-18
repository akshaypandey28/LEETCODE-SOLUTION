class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans=keysPressed[0];
        int maxi=releaseTimes[0];
        for(int i=1; i<releaseTimes.size();i++){
            int value=releaseTimes[i]-releaseTimes[i-1];
            if(value>maxi){
                maxi=value;
                ans=keysPressed[i];
            }
            else if(value==maxi) ans=max(ans,keysPressed[i]);
        }
        return ans;
    }
};