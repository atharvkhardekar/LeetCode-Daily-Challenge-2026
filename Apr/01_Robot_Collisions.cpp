// 2751. Robot Collisions
// Daily Challenge - 01/04/2026

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st; 

        for (int i : idx) {

            if (directions[i] == 'R') {
                st.push(i);
            } 
            else {
                while (!st.empty() && healths[i] > 0) {
                    int j = st.top();

                    if (healths[j] < healths[i]) {
                        st.pop();
                        healths[i]--;
                        healths[j] = 0;
                    } 
                    else if (healths[j] > healths[i]) {
                        healths[j]--;
                        healths[i] = 0;
                        break;
                    } 
                    else {
                        st.pop();
                        healths[i] = 0;
                        healths[j] = 0;
                        break;
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};