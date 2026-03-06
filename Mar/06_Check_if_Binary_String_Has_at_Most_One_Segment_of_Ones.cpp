// 1784. Check if Binary String Has at Most One Segment of Ones
// Daily Challenge - 06/03/2026

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seenZero = false;

        for(char c : s) {
            if(c == '0')
                seenZero = true;
            else if(seenZero)
                return false;
        }

        return true;
    }
};