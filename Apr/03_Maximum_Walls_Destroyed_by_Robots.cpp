// 3661. Maximum Walls Destroyed by Robots
// Daily Challenge - 03/04/2026

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        
        int n = robots.size();

        vector<int> leftCount(n, 0), rightCount(n, 0), overlapWalls(n, 0);

        unordered_map<int, int> distMap;
        for (int i = 0; i < n; i++) {
            distMap[robots[i]] = distance[i];
        }

        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());

        for (int i = 0; i < n; i++) {

            int robotPos = robots[i];
            int reach = distMap[robotPos];

            int wallsTillRobot =
                upper_bound(walls.begin(), walls.end(), robotPos) - walls.begin();

            int leftStart;
            if (i > 0) {
                leftStart = lower_bound(
                                walls.begin(), walls.end(),
                                max(robotPos - reach, robots[i - 1] + 1)
                            ) - walls.begin();
            } else {
                leftStart = lower_bound(
                                walls.begin(), walls.end(),
                                robotPos - reach
                            ) - walls.begin();
            }

            leftCount[i] = wallsTillRobot - leftStart;

            int rightEnd;
            if (i < n - 1) {
                rightEnd = upper_bound(
                               walls.begin(), walls.end(),
                               min(robotPos + reach, robots[i + 1] - 1)
                           ) - walls.begin();
            } else {
                rightEnd = upper_bound(
                               walls.begin(), walls.end(),
                               robotPos + reach
                           ) - walls.begin();
            }

            int wallsFromRobot =
                lower_bound(walls.begin(), walls.end(), robotPos) - walls.begin();

            rightCount[i] = rightEnd - wallsFromRobot;

            if (i == 0) continue;

            int prevRobotWalls =
                lower_bound(walls.begin(), walls.end(), robots[i - 1]) - walls.begin();

            overlapWalls[i] = wallsTillRobot - prevRobotWalls;
        }

        int bestLeft = leftCount[0];
        int bestRight = rightCount[0];

        for (int i = 1; i < n; i++) {

            int takeLeft = max(
                bestLeft + leftCount[i],
                bestRight - rightCount[i - 1] +
                min(leftCount[i] + rightCount[i - 1], overlapWalls[i])
            );

            int takeRight = max(
                bestLeft + rightCount[i],
                bestRight + rightCount[i]
            );

            bestLeft = takeLeft;
            bestRight = takeRight;
        }

        return max(bestLeft, bestRight);
    }
};