// 2515. Shortest Distance to Target String in a Circular Array
// Daily Challenge - 15/04/2026

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int diff = abs(i - startIndex);
                int dist = min(diff, n - diff);
                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


// Alternative solution - Early Exit BFS Style

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        for (int d = 0; d < n; d++) {
            int left = (startIndex - d + n) % n;
            int right = (startIndex + d) % n;

            if (words[left] == target || words[right] == target) {
                return d;
            }
        }

        return -1;
    }
};