// 3453. Separate Squares I
// Daily Challenge - 13/01/2026

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double halfArea = 0;
        vector<tuple<int, bool, int>> events; 

        for (auto &sq : squares) {
            int y = sq[1], l = sq[2];
            halfArea += (long double)l * l;
            events.push_back({y, true, l});
            events.push_back({y + l, false, l});
        }
        halfArea /= 2.0L;
        
        sort(events.begin(), events.end(),
            [](auto &a, auto &b){
                return get<0>(a) < get<0>(b);
            });

        long double area = 0.0L;
        long long width = 0;
        long double prevY = get<0>(events[0]);

        for (auto &ev : events) {
            long double curY = get<0>(ev);
            long double dy = curY - prevY;

            long double added = width * dy;
            if (area + added >= halfArea) {
                long double remain = halfArea - area;
                return prevY + remain / width;
            }
            area += added;

            if (get<1>(ev))
                width += get<2>(ev);
            else
                width -= get<2>(ev);

            prevY = curY;
        }

        return prevY; 
    }
};
