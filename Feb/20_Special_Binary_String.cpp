// 761. Special Binary String
// Daily Challenge - 20/02/2026

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int balance = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            balance += (s[i] == '1') ? 1 : -1;

            if (balance == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        sort(parts.begin(), parts.end(), greater<string>());

        string result;
        for (auto &p : parts) {
            result += p;
        }

        return result;
    }
};
