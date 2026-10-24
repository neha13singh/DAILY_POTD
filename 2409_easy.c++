//approach 1
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        vector<int> month(4);
        vector<int> date(4);

        // Store months
        month[0] = stoi(arriveAlice.substr(0, 2));
        month[1] = stoi(leaveAlice.substr(0, 2));
        month[2] = stoi(arriveBob.substr(0, 2));
        month[3] = stoi(leaveBob.substr(0, 2));

        // Store dates
        date[0] = stoi(arriveAlice.substr(3, 2));
        date[1] = stoi(leaveAlice.substr(3, 2));
        date[2] = stoi(arriveBob.substr(3, 2));
        date[3] = stoi(leaveBob.substr(3, 2));

        vector<int> daysInMonth = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        vector<int> alice;
        vector<int> bob;

        // Generate all dates for Alice
        for (int m = month[0]; m <= month[1]; m++) {
            int start = (m == month[0]) ? date[0] : 1;
            int end = (m == month[1]) ? date[1] : daysInMonth[m - 1];

            for (int d = start; d <= end; d++) {
                alice.push_back(m * 100 + d);
            }
        }

        // Generate all dates for Bob
        for (int m = month[2]; m <= month[3]; m++) {
            int start = (m == month[2]) ? date[2] : 1;
            int end = (m == month[3]) ? date[3] : daysInMonth[m - 1];

            for (int d = start; d <= end; d++) {
                bob.push_back(m * 100 + d);
            }
        }

        // Find common dates
        int count = 0;

        for (int i = 0; i < alice.size(); i++) {
            for (int j = 0; j < bob.size(); j++) {
                if (alice[i] == bob[j]) {
                    count++;
                }
            }
        }

        return count;
    }
};


//approach 2
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        vector<int> daysInMonth = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        vector<int> cumsum(13, 0);

        for (int i = 1; i < 13; i++) {
            cumsum[i] = cumsum[i - 1] + daysInMonth[i - 1];
            cout<<cumsum[i]<<" ";
        }
        cout<<endl;

        int alicedate = stoi(arriveAlice.substr(3, 2));
        int alicedate2 = stoi(leaveAlice.substr(3, 2));
        int bobdate = stoi(arriveBob.substr(3, 2));
        int bobdate2 = stoi(leaveBob.substr(3, 2));

        int alicemonth = stoi(arriveAlice.substr(0, 2));
        int alicemonth2 = stoi(leaveAlice.substr(0, 2));
        int bobmonth = stoi(arriveBob.substr(0, 2));
        int bobmonth2 = stoi(leaveBob.substr(0, 2));

        int aliceday = cumsum[alicemonth - 1] + alicedate;
        int aliceday2 = cumsum[alicemonth2 - 1] + alicedate2;

        int bobday = cumsum[bobmonth - 1] + bobdate;
        int bobday2 = cumsum[bobmonth2 - 1] + bobdate2;

        int start = max(aliceday, bobday);
        int end = min(aliceday2, bobday2);

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};
