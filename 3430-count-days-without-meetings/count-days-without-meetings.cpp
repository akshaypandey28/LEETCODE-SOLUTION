class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> temp = meetings[0];
        int days_meeting = 0;
        
        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] <= temp[1]) {
                // Overlapping or adjacent intervals, merge them
                temp[1] = max(temp[1], meetings[i][1]);
            } else {
                days_meeting += temp[1] - temp[0] + 1;
                temp = meetings[i];
            }
        }
        days_meeting += temp[1] - temp[0] + 1;
        
        return days - days_meeting;
    }
};