// 796. Rotate String
// Daily Challenge - 03/05/2026

class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if (s.size() != goal.size())
            return false;

        string doubled = s + s;

        return doubled.find(goal) != string::npos;
    }
};