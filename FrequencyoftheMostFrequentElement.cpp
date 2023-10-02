class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long i=0, ans = 1, n = nums.size(), sum=0;
        for(int j=0; j<n; j++) {
            sum += nums[j];
            while((j-i+1)*nums[j]-sum > k) sum -= nums[i++];
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
