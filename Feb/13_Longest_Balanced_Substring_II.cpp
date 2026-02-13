// 3714. Longest Balanced Substring II
// Daily Challenge - 13/02/2026

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        char chars[3] = {'a', 'b', 'c'};

        for (int mask = 1; mask < 8; ++mask) {
            vector<char> subset;
            for (int i = 0; i < 3; ++i) {
                if ((mask >> i) & 1) subset.push_back(chars[i]);
            }

            unordered_map<long long, int> seen;
            seen[0] = -1; 
            
            int counts[3] = {0, 0, 0};
            int lastInvalid = -1;

            for (int j = 0; j < n; ++j) {
                int charIdx = -1;
                for (int k = 0; k < subset.size(); ++k) {
                    if (s[j] == subset[k]) {
                        charIdx = k;
                        break;
                    }
                }

                if (charIdx == -1) {
                    seen.clear();
                    counts[0] = counts[1] = counts[2] = 0;
                    seen[0] = j;
                    lastInvalid = j;
                } else {
                    counts[charIdx]++;
                    
                    long long state = 0;
                    if (subset.size() == 2) {
                        state = counts[0] - counts[1];
                    } else if (subset.size() == 3) {
                        state = ((long long)(counts[0] - counts[1]) << 32) | (unsigned int)(counts[1] - counts[2]);
                    }

                    if (seen.count(state)) {
                        bool ready = true;
                        for(int k = 0; k < subset.size(); ++k) if(counts[k] == 0) ready = false;
                        if(ready) maxLen = max(maxLen, j - seen[state]);
                    } else {
                        seen[state] = j;
                    }
                }
            }
        }
        return maxLen;
    }
};