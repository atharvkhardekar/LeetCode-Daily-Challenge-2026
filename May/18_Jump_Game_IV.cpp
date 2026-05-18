// 1345. Jump Game IV
// Daily Challenge - 18/05/2026

constexpr int MAX_SIZE = 50001;

bitset<MAX_SIZE> visited;
int bfsQueue[MAX_SIZE];
int leftPtr = 0, rightPtr = 0;

class Solution {
public:
    static int minJumps(vector<int>& arr) {
        int n = arr.size();

        visited.reset();

        unordered_map<int, vector<int>> positions;
        positions.reserve(n);

        for (int i = 0; i < n; ++i) {
            positions[arr[i]].push_back(i);
        }

        leftPtr = rightPtr = 0;
        bfsQueue[rightPtr++] = 0;

        int jumps = 0;

        while (leftPtr < rightPtr) {

            int levelSize = rightPtr - leftPtr;

            while (levelSize--) {

                int currentIndex = bfsQueue[leftPtr++];

                if (currentIndex == n - 1) {
                    return jumps;
                }

                if (currentIndex - 1 >= 0 && !visited[currentIndex - 1]) {
                    bfsQueue[rightPtr++] = currentIndex - 1;
                    visited[currentIndex - 1] = 1;
                }

                if (currentIndex + 1 < n && !visited[currentIndex + 1]) {
                    bfsQueue[rightPtr++] = currentIndex + 1;
                    visited[currentIndex + 1] = 1;
                }

                for (int nextIndex : positions[arr[currentIndex]]) {

                    if (!visited[nextIndex]) {
                        bfsQueue[rightPtr++] = nextIndex;
                        visited[nextIndex] = 1;
                    }
                }

                positions[arr[currentIndex]].clear();
            }

            ++jumps;
        }

        return -1;
    }
};
