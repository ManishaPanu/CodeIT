class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        bool inserted = false;

        for(int i=0; i<n; i++) {
            if(inserted || intervals[i][1] < newInterval[0]) {
                //new interval lies to the right
                ans.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]) {
                //new interval lies to the left
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                inserted = true;
            }
            else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        if(!inserted) {
            ans.push_back(newInterval); // If newInterval is the largest interval
        }
        return ans;
    }
};
