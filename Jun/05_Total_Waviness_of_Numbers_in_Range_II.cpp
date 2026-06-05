// 3753. Total Waviness of Numbers in Range II
// Daily Challenge - 05/06/2026

using ll = long long;

class Solution {
    static inline int validPatterns[570];

    static inline bool initialized = []() {
        int idx = 0;

        for (int num = 0; num < 1000; num++) {
            int right = num % 10;
            int middle = (num / 10) % 10;
            int left = (num / 100) % 10;

            if ((middle > max(left, right)) ||
                (middle < min(left, right))) {
                validPatterns[idx++] = num;
            }
        }
        return true;
    }();

public:
    ll totalWaviness(ll num1, ll num2) {
        return getWaveCount(num2) - getWaveCount(num1 - 1);
    }

private:
    ll getWaveCount(ll limit) {
        if (limit < 100)
            return 0;

        ll result = 0;

        for (int pattern : validPatterns) {
            result += calculateOccurrences(limit, pattern);
        }

        return result;
    }

    ll calculateOccurrences(ll limit, int pattern) {
        ll leadingZeroAdjustment = (pattern < 100);
        ll total = 0;
        ll placeValue = 1;

        while (placeValue * 100 <= limit) {
            ll higherPart = limit / (placeValue * 1000);
            ll currentBlock = (limit / placeValue) % 1000;
            ll lowerPart = limit % placeValue;

            ll fullBlocks = 0;

            if (currentBlock > pattern) {
                fullBlocks = higherPart - leadingZeroAdjustment + 1;
            }
            else if (currentBlock == pattern) {
                fullBlocks = max(0LL, higherPart - leadingZeroAdjustment);
                total += lowerPart + 1;
            }
            else {
                fullBlocks = max(0LL, higherPart - leadingZeroAdjustment);
            }

            total += fullBlocks * placeValue;
            placeValue *= 10;
        }

        return total;
    }
};
