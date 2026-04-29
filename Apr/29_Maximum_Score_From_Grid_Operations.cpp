// 3225. Maximum Score From Grid Operations
// Daily Challenge - 29/04/2026

class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        if (cols == 1) return 0;

        vector<vector<long long>> prefix(cols,
                                         vector<long long>(rows + 1, 0));

        for (int col = 0; col < cols; col++) {
            for (int row = 0; row < rows; row++) {
                prefix[col][row + 1] =
                    prefix[col][row] + grid[row][col];
            }
        }

        vector<vector<long long>> dp(rows + 1,
                                     vector<long long>(rows + 1, 0));

        vector<vector<long long>> prefixBest(rows + 1,
                                             vector<long long>(rows + 1, 0));

        vector<vector<long long>> suffixBest(rows + 1,
                                             vector<long long>(rows + 1, 0));

        for (int col = 1; col < cols; col++) {

            vector<vector<long long>> nextDP(rows + 1,
                                             vector<long long>(rows + 1, 0));

            for (int currHeight = 0; currHeight <= rows; currHeight++) {

                for (int prevHeight = 0;
                     prevHeight <= rows;
                     prevHeight++) {

                    if (currHeight <= prevHeight) {

                        long long add =
                            prefix[col][prevHeight] -
                            prefix[col][currHeight];

                        nextDP[currHeight][prevHeight] = max(
                            nextDP[currHeight][prevHeight],
                            suffixBest[prevHeight][0] + add
                        );
                    }

                    else {

                        long long add =
                            prefix[col - 1][currHeight] -
                            prefix[col - 1][prevHeight];

                        nextDP[currHeight][prevHeight] = max({
                            nextDP[currHeight][prevHeight],
                            suffixBest[prevHeight][currHeight],
                            prefixBest[prevHeight][currHeight] + add
                        });
                    }
                }
            }

            for (int currHeight = 0;
                 currHeight <= rows;
                 currHeight++) {

                prefixBest[currHeight][0] =
                    nextDP[currHeight][0];

                for (int prevHeight = 1;
                     prevHeight <= rows;
                     prevHeight++) {

                    long long deduction = 0;

                    if (prevHeight > currHeight) {
                        deduction =
                            prefix[col][prevHeight] -
                            prefix[col][currHeight];
                    }

                    prefixBest[currHeight][prevHeight] = max(
                        prefixBest[currHeight][prevHeight - 1],
                        nextDP[currHeight][prevHeight] - deduction
                    );
                }

                suffixBest[currHeight][rows] =
                    nextDP[currHeight][rows];

                for (int prevHeight = rows - 1;
                     prevHeight >= 0;
                     prevHeight--) {

                    suffixBest[currHeight][prevHeight] = max(
                        suffixBest[currHeight][prevHeight + 1],
                        nextDP[currHeight][prevHeight]
                    );
                }
            }

            dp = move(nextDP);
        }

        long long answer = 0;

        for (int height = 0; height <= rows; height++) {
            answer = max({
                answer,
                dp[0][height],
                dp[rows][height]
            });
        }

        return answer;
    }
};