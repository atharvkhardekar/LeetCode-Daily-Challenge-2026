// 744. Find Smallest Letter Greater Than Target
// Daily Challenge - 31/01/2026

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        char ans = letters[0];  
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (letters[mid] > target) {
                ans = letters[mid];
                right = mid - 1;  
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};