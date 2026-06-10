// 3691. Maximum Total Subarray Value II
// Daily Challenge - 10/06/2026

class RangeQuery {
    vector<vector<int>> mnTable, mxTable;

public:
    RangeQuery(const vector<int>& arr) {
        int n = arr.size();
        int levels = bit_width((size_t)n);

        mnTable.assign(levels, vector<int>(n));
        mxTable.assign(levels, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mnTable[0][i] = arr[i];
            mxTable[0][i] = arr[i];
        }

        for (int lvl = 1; lvl < levels; lvl++) {
            int len = 1 << lvl;

            for (int start = 0; start + len <= n; start++) {
                int half = 1 << (lvl - 1);

                mnTable[lvl][start] =
                    min(mnTable[lvl - 1][start],
                        mnTable[lvl - 1][start + half]);

                mxTable[lvl][start] =
                    max(mxTable[lvl - 1][start],
                        mxTable[lvl - 1][start + half]);
            }
        }
    }

    int getDifference(int left, int right) {
        int power = bit_width((uint32_t)(right - left)) - 1;
        int segmentLength = 1 << power;

        int maximum =
            max(mxTable[power][left],
                mxTable[power][right - segmentLength]);

        int minimum =
            min(mnTable[power][left],
                mnTable[power][right - segmentLength]);

        return maximum - minimum;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        RangeQuery st(nums);
        priority_queue<tuple<int, int, int>> heap;

        for (int start = 0; start < n; start++) {
            heap.emplace(st.getDifference(start, n), start, n);
        }

        long long answer = 0;

        while (!heap.empty() && get<0>(heap.top()) > 0 && k--) {
            auto [diff, left, right] = heap.top();
            heap.pop();

            answer += diff;

            heap.emplace(
                st.getDifference(left, right - 1),
                left,
                right - 1
            );
        }

        return answer;
    }
};
