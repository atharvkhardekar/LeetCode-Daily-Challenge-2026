// 1306. Jump Game III
// Daily Challenge - 17/05/2026

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);

        queue<int> q;
        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0)
                return true;

            int forward = i + arr[i];
            int backward = i - arr[i];

            if (forward < n && !vis[forward]) {
                vis[forward] = true;
                q.push(forward);
            }

            if (backward >= 0 && !vis[backward]) {
                vis[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};
