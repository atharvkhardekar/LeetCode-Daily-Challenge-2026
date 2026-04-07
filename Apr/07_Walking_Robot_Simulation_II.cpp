// 2069. Walking Robot Simulation II
// Daily Challenge - 07/04/2026

class Robot {
public:
    int w, h, x, y, dir;
    int cycle;

    vector<pair<int,int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<string> dnames = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0; 
        cycle = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        num %= cycle;
        if (num == 0 && x == 0 && y == 0) {
            dir = 3; 
            return;
        }

        while (num--) {
            int nx = x + dirs[dir].first;
            int ny = y + dirs[dir].second;

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4;
                nx = x + dirs[dir].first;
                ny = y + dirs[dir].second;
            }

            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dnames[dir];
    }
};