// 2943. Maximize Area of Square Hole in Grid
// Daily Challenge - 15/01/2026

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto maxGap = [&](vector<int>& bars) {
            sort(bars.begin(), bars.end());
            int longest = 1, current = 1;
            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] == bars[i - 1] + 1) {
                    current++;
                    longest = max(longest, current);
                } else {
                    current = 1;
                }
            }
            
            return longest + 1;
        };

        int gapH = maxGap(hBars);
        int gapV = maxGap(vBars);

        int side = min(gapH, gapV);
        return side * side;
    }
};
