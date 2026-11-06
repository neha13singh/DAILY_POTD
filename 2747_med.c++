class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        // Store query with its original index
        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(queries.size());

        int left = 0, right = 0;
        int count = 0;

        for(auto [time, idx] : q) {

            // Add logs up to current query time
            while(right < logs.size() &&
                  logs[right][1] <= time) {

                int server = logs[right][0];

                if(freq[server] == 0)
                    count++;

                freq[server]++;
                right++;
            }

            // Remove logs outside the interval
            while(left < right &&
                  logs[left][1] < time - x) {

                int server = logs[left][0];

                freq[server]--;

                if(freq[server] == 0)
                    count--;

                left++;
            }

            ans[idx] = n - count;
        }

        return ans;
    }
};