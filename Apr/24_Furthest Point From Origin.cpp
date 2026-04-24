// 2833. Furthest Point From Origin
// Daily Challenge - 24/04/2026

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, U = 0;
        
        for (char c : moves) {
            if (c == 'L') L++;
            else if (c == 'R') R++;
            else U++;
        }
        
        return abs(R - L) + U;
    }
};
