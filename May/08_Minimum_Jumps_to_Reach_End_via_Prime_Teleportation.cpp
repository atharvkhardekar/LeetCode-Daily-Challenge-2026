// 3629. Minimum Jumps to Reach End via Prime Teleportation
// Daily Challenge - 08/05/2026

class Solution {
public:
    
    vector<int> getPrimes(int mx) {
        vector<bool> isPrime(mx + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= mx; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= mx; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= mx; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return 0;
        }

        int mx = *max_element(nums.begin(), nums.end());

        unordered_map<int, vector<int>> divisible;

        vector<int> primes = getPrimes(mx);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            int temp = x;

            for (int p : primes) {
                if (1LL * p * p > temp) {
                    break;
                }

                if (temp % p == 0) {
                    divisible[p].push_back(i);

                    while (temp % p == 0) {
                        temp /= p;
                    }
                }
            }

            if (temp > 1) {
                divisible[temp].push_back(i);
            }
        }

        vector<bool> isPrime(mx + 1, true);
        if (mx >= 0) isPrime[0] = false;
        if (mx >= 1) isPrime[1] = false;

        for (int i = 2; i * i <= mx; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= mx; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1) {
                return d;
            }

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (isPrime[val] && !usedPrime.count(val)) {

                usedPrime.insert(val);

                for (int nxt : divisible[val]) {

                    if (nxt != i && dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }
            }
        }

        return -1;
    }
};