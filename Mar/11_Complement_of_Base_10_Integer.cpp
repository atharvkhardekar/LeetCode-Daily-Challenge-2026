// 1009. Complement of Base 10 Integer
// Daily Challenge - 11/03/2026

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        unsigned int mask = 0;
        int temp = n;
        
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        
        return n ^ mask;
    }
};