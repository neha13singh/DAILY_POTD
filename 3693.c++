class Solution {
public:
    int n;

    int solve(int i, vector<int>& costs, vector<int>& dp) {
        if (i == n) return 0;

        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for (int j = 1; j <= 3; j++) {
            if (i + j <= n) {
                int cost = costs[i + j] + j * j
                         + solve(i + j, costs, dp);

                ans = min(ans, cost);
            }
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0);

        this->n = n;

        vector<int> dp(n + 1, -1);

        return solve(0, costs, dp);
    }
};
