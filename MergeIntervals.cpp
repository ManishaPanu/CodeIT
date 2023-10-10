class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i=0; i<n; i++) {
            int first = intervals[i][0];
            int second = intervals[i][1];
            if(ans.empty() || ans.back()[1] < first) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(second, ans.back()[1]);
            }
        }
        return ans;
    }
};
