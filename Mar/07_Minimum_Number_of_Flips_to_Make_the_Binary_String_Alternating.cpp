// 1888. Minimum Number of Flips to Make the Binary String Alternating
// Daily Challenge - 07/03/2026

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string doubled = s + s;

        string alt1 = "", alt2 = "";
        for(int i = 0; i < 2 * n; i++) {
            alt1 += (i % 2 ? '1' : '0');
            alt2 += (i % 2 ? '0' : '1');
        }

        int res = INT_MAX;
        int diff1 = 0, diff2 = 0;
        int left = 0;

        for(int right = 0; right < 2 * n; right++) {

            if(doubled[right] != alt1[right]) diff1++;
            if(doubled[right] != alt2[right]) diff2++;

            if(right - left + 1 > n) {
                if(doubled[left] != alt1[left]) diff1--;
                if(doubled[left] != alt2[left]) diff2--;
                left++;
            }

            if(right - left + 1 == n)
                res = min(res, min(diff1, diff2));
        }

        return res;
    }
};
