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

