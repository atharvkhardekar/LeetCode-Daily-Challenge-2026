// 3474. Lexicographically Smallest Generated String
// Daily Challenge - 31/03/2026

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        string word(len, '?');

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return ""; 
                    }
                }
            }
        }

        for (char &c : word) {
            if (c == '?') c = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool broken = false;

                    for (int j = m - 1; j >= 0 && !broken; j--) {
                        int pos = i + j;

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == word[pos]) continue;

                            char original = word[pos];
                            word[pos] = c;

                            bool stillMatch = true;
                            for (int k = 0; k < m; k++) {
                                if (word[i + k] != str2[k]) {
                                    stillMatch = false;
                                    break;
                                }
                            }

                            bool valid = true;
                            for (int t = max(0, pos - m + 1); t <= min(n - 1, pos); t++) {
                                if (str1[t] == 'T') {
                                    for (int k = 0; k < m; k++) {
                                        if (word[t + k] != str2[k]) {
                                            valid = false;
                                            break;
                                        }
                                    }
                                }
                                if (!valid) break;
                            }

                            if (!stillMatch && valid) {
                                broken = true;
                                break;
                            }

                            word[pos] = original; 
                        }
                    }

                    if (!broken) return "";
                }
            }
        }

        for (int i = 0; i < n; i++) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (word[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }

            if ((str1[i] == 'T' && !match) || (str1[i] == 'F' && match)) {
                return "";
            }
        }

        return word;
    }
};