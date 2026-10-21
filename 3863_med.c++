class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string sorted = s;
        sort(sorted.begin(), sorted.end());

        if (s == sorted) return 0;
        if (n == 2) return -1;

        string s1 = s.substr(0, n - 1);
        string s2 = s.substr(1);

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if (s.substr(0, 1) + s2 == sorted ||
            s1 + s.substr(n - 1) == sorted)
            return 1;

        string s3 = s.substr(0, 1) + s2;
        string s4 = s1 + s.substr(n - 1);

        string s5 = s3.substr(0, n - 1);
        sort(s5.begin(), s5.end());

        if (s5 + s3.substr(n - 1) == sorted)
            return 2;

        string s7 = s4.substr(1);
        sort(s7.begin(), s7.end());

        if (s4.substr(0, 1) + s7 == sorted)
            return 2;

        return 3;
    }
};


------------------------------------------------

class Solution {
public:
    int minOperations(auto& s) {
        int n = s.length();
        char mn = s[0], mx = s[0];
        bool isSorted = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) isSorted = 0;
            mn = min(mn, s[i]);
            mx = max(mx, s[i]);
        }

        if (isSorted) return 0;
        if (n == 2) return -1;
        if (s.front() == mn || s.back() == mx)
            return 1;
        //  if (s.front() == mx && s.back() == mn)
        //     return 3;

        for (int i = 1; i < n - 1; i++)
            if (s[i] == mn || s[i] == mx)
                return 2;

        return 3;
    }
};