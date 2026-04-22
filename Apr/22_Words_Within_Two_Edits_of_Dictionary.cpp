// 2452. Words Within Two Edits of Dictionary
// Daily Challenge - 22/04/2026

class Solution {
public:
    bool isValid(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 2) return false;
            }
        }
        return true;
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        
        for (auto &q : queries) {
            for (auto &d : dictionary) {
                if (isValid(q, d)) {
                    ans.push_back(q);
                    break; 
                }
            }
        }
        
        return ans;
    }
};
