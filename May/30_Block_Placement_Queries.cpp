// 3161. Block Placement Queries
// Daily Challenge - 30/05/2026

class Solution {
public:

    vector<int> segmentTree;
    static constexpr int LIMIT = 50000;

    void pointUpdate(int node, int start, int end,
                     int position, int value) {

        if (start == end) {
            segmentTree[node] = value;
            return;
        }

        int middle = start + (end - start) / 2;

        if (position <= middle) {
            pointUpdate(node * 2, start, middle,
                        position, value);
        } else {
            pointUpdate(node * 2 + 1, middle + 1, end,
                        position, value);
        }

        segmentTree[node] = max(
            segmentTree[node * 2],
            segmentTree[node * 2 + 1]
        );
    }

    int rangeMaximum(int node, int start, int end,
                     int left, int right) {

        if (right < start || left > end)
            return 0;

        if (left <= start && end <= right)
            return segmentTree[node];

        int middle = start + (end - start) / 2;

        return max(
            rangeMaximum(node * 2, start, middle, left, right),
            rangeMaximum(node * 2 + 1, middle + 1, end, left, right)
        );
    }

    vector<bool> getResults(vector<vector<int>>& queries) {

        segmentTree.assign(4 * (LIMIT + 1), 0);

        set<int> obstaclePositions;
        obstaclePositions.insert(0);

        for (auto &query : queries) {
            if (query[0] == 1) {
                obstaclePositions.insert(query[1]);
            }
        }

        vector<int> coordinates(
            obstaclePositions.begin(),
            obstaclePositions.end()
        );

        for (int i = 1; i < (int)coordinates.size(); i++) {

            int currentPos = coordinates[i];
            int previousPos = coordinates[i - 1];

            pointUpdate(
                1, 0, LIMIT,
                currentPos,
                currentPos - previousPos
            );
        }

        vector<bool> result;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            if (queries[i][0] == 2) {

                int x = queries[i][1];
                int blockSize = queries[i][2];

                auto it = prev(obstaclePositions.upper_bound(x));

                int nearestLeftObstacle = *it;

                int largestGap = rangeMaximum(
                    1, 0, LIMIT,
                    0, nearestLeftObstacle
                );

                largestGap = max(
                    largestGap,
                    x - nearestLeftObstacle
                );

                result.push_back(largestGap >= blockSize);
            }
            else {

                int obstacle = queries[i][1];

                auto currentIt = obstaclePositions.find(obstacle);

                int leftObstacle = *prev(currentIt);

                pointUpdate(
                    1, 0, LIMIT,
                    obstacle,
                    0
                );

                auto nextObstacleIt = next(currentIt);

                if (nextObstacleIt != obstaclePositions.end()) {

                    int rightObstacle = *nextObstacleIt;

                    pointUpdate(
                        1, 0, LIMIT,
                        rightObstacle,
                        rightObstacle - leftObstacle
                    );
                }

                obstaclePositions.erase(currentIt);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};