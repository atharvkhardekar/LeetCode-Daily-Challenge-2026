// 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
// Daily Challenge - 01/03/2026

class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for (char c : n) {
            maxDigit = max(maxDigit, c - '0');
        }
        return maxDigit;
    }
};
