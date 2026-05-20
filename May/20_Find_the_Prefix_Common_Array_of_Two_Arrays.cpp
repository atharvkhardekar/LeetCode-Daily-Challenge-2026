// 2657. Find the Prefix Common Array of Two Arrays
// Daily Challenge - 20/05/2026

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> result(n, 0);
        unordered_set<int> seen; 
        
        int commonCount = 0;
        for (int i = 0; i < n; ++i) {
            if (seen.count(A[i])) {
                ++commonCount; 
            } else {
                seen.insert(A[i]);
            }
            
            if (seen.count(B[i])) {
                ++commonCount; 
            } else {
                seen.insert(B[i]);
            }
            result[i] = commonCount; 
        }
        return result;
    }
};