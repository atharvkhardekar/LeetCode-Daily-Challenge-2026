// 1653. Minimum Deletions to Make String Balanced
// Daily Challenge - 07/02/2026

class Solution {
public:
    int minimumDeletions(string s) {
        int deletions = 0;  
        int countB = 0;     

        for (char c : s) {
            if (c == 'b') {
                countB++;
            } else { 
                deletions = min(deletions + 1, countB);
            }
        }
        return deletions;
    }
};
