class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes(timePoints.size());

        // Convert times to minutes
        for (int i = 0; i < timePoints.size(); ++i) {
            int h = stoi(timePoints[i].substr(0, 2)); // extract hours
            int m = stoi(timePoints[i].substr(3));    // extract minutes
            minutes[i] = h * 60 + m;                 // convert to total minutes
        }

        // Sort times in ascending order
        sort(minutes.begin(), minutes.end());

        // Find minimum difference across adjacent elements, considering midnight wrap-around
        int minDiff = INT_MAX;
        for (int i = 0; i < minutes.size() - 1; ++i) {
            minDiff = min(minDiff, minutes[i + 1] - minutes[i]);
        }

        // Handle the wrap-around by comparing the last and the first time (with midnight in mind)
        // Instead of the original line, you can add 1440 to the first time for correct comparison
        minDiff = min(minDiff, (minutes[0] + 1440) - minutes.back());

        return minDiff;
    }
};
