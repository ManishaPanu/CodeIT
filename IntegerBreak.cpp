class Solution {
public:
    int dp[59];
    int solve(int n) {
        int res = INT_MIN;
        if(dp[n] != -1) return dp[n];
        for(int i=1; i<=(n-i); i++) {
            int ans = i * max(n-i,solve(n-i));
            res = max(res, ans);
        }
        return dp[n] = res;
    }

    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
