// 1665. Minimum Initial Energy to Finish Tasks
// Daily Challenge - 12/05/2026

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(), tasks.end(),
            [](vector<int>& x, vector<int>& y) {
                return (x[1] - x[0]) > (y[1] - y[0]);
            }
        );

        int initialEnergy = tasks[0][1];
        int currentEnergy = tasks[0][1] - tasks[0][0];
        int extraNeeded = 0;

        for (int i = 1; i < tasks.size(); i++) {

            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            if (currentEnergy < minimum) {
                extraNeeded += (minimum - currentEnergy);
                currentEnergy = minimum;
            }

            currentEnergy -= actual;
        }

        return initialEnergy + extraNeeded;
    }
};